Caching application settings like `setting_item` is an excellent way to improve performance and ensure seamless operation, especially during bootstrapping. Below is a step-by-step guide on how to implement caching for your settings in the most efficient and maintainable way:

---

### **1. Cache Settings at Application Boot**
Cache the entire settings table as a key-value pair (e.g., `name` => `value`). This way, settings are fetched once and reused across the application without hitting the database repeatedly.

#### **Updated `setting_item` Function with Cache**
```php
if (!function_exists('setting_item')) {
    function setting_item(string $name)
    {
        static $settingsCache = null;

        // Load settings into cache on the first call
        if ($settingsCache === null) {
            $settingsCache = cache()->rememberForever('settings_cache', function () {
                return \App\Models\Setting::all()->pluck('value', 'name')->toArray();
            });
        }

        // Return the decoded value or null if not found
        $value = $settingsCache[$name] ?? null;
        return json_decode($value);
    }
}
```

#### **Explanation**
- **`cache()->rememberForever`**: Ensures the settings are cached permanently unless manually cleared or updated.
- **Static Cache**: Prevents unnecessary cache lookups during a single request lifecycle.
- Settings are stored as key-value pairs, making retrieval fast and efficient.

---

### **2. Automatically Update Cache on Setting Change**
To ensure the cache reflects the latest settings, you can update the cache whenever the settings are modified.

#### **Use Model Events**
In the `Setting` model, use the `saved` and `deleted` events to refresh the cache.

```php
namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Setting extends Model
{
    protected $fillable = ['name', 'value'];

    // Boot method to handle model events
    protected static function boot()
    {
        parent::boot();

        static::saved(function () {
            cache()->forget('settings_cache');
            cache()->rememberForever('settings_cache', function () {
                return self::all()->pluck('value', 'name')->toArray();
            });
        });

        static::deleted(function () {
            cache()->forget('settings_cache');
            cache()->rememberForever('settings_cache', function () {
                return self::all()->pluck('value', 'name')->toArray();
            });
        });
    }
}
```

---

### **3. Preload Settings into Configuration**
For global access, preload settings into Laravel’s configuration during application boot.

#### **Create a Service Provider**
Create a custom service provider to load cached settings into `config`.

```php
namespace App\Providers;

use Illuminate\Support\Facades\Config;
use Illuminate\Support\Facades\Cache;
use Illuminate\Support\ServiceProvider;

class SettingServiceProvider extends ServiceProvider
{
    public function boot()
    {
        // Load settings from cache
        $settings = cache()->rememberForever('settings_cache', function () {
            return \App\Models\Setting::all()->pluck('value', 'name')->toArray();
        });

        // Add settings to Laravel's config
        foreach ($settings as $key => $value) {
            Config::set('app_settings.' . $key, json_decode($value));
        }
    }
}
```

#### **Register the Service Provider**
Add it to `config/app.php` under `providers`:

```php
'providers' => [
    // Other providers
    App\Providers\SettingServiceProvider::class,
];
```

#### **Access Settings via `config()`**
Once settings are loaded, you can access them anywhere in your application:

```php
$passRates = config('app_settings.pass_rates');
```

---

### **4. Command to Clear and Refresh Cache**
Create an Artisan command to manually clear and refresh the settings cache.

#### **Artisan Command**
```php
namespace App\Console\Commands;

use Illuminate\Console\Command;

class RefreshSettingsCache extends Command
{
    protected $signature = 'settings:refresh';
    protected $description = 'Refresh the application settings cache';

    public function handle()
    {
        cache()->forget('settings_cache');
        cache()->rememberForever('settings_cache', function () {
            return \App\Models\Setting::all()->pluck('value', 'name')->toArray();
        });

        $this->info('Settings cache refreshed successfully!');
    }
}
```

#### **Register the Command**
Add the command to `App\Console\Kernel`:

```php
protected $commands = [
    \App\Console\Commands\RefreshSettingsCache::class,
];
```

#### **Run the Command**
```bash
php artisan settings:refresh
```

---

### **5. Testing the Setup**
1. **Cache Loading**:
   - Clear and refresh the cache using `php artisan settings:refresh`.
   - Confirm the settings are cached with:
     ```php
     dd(cache('settings_cache'));
     ```

2. **Cache Updating**:
   - Create, update, or delete a `Setting` record.
   - Verify the cache is updated automatically using:
     ```php
     dd(cache('settings_cache'));
     ```

3. **Global Access**:
   - Access cached settings using:
     ```php
     $passRates = config('app_settings.pass_rates');
     ```

---

### **6. Cache Storage Configuration**
Ensure your application uses an appropriate caching driver (e.g., Redis, Memcached, or file-based caching). Set it in `.env`:

```env
CACHE_DRIVER=redis
```

Clear and cache settings again:
```bash
php artisan cache:clear
php artisan settings:refresh
```

---

### **Summary**
- **Caching**: Use `cache()->rememberForever` to store settings permanently.
- **Automatic Updates**: Refresh the cache on `saved` and `deleted` events in the `Setting` model.
- **Preloading**: Use a service provider to preload settings into Laravel’s configuration for easy access.
- **Commands**: Create an Artisan command for manual cache refresh.

This approach ensures optimal performance and easy maintenance of your application settings.
