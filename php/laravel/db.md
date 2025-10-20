# Database

## Create Model and Migration files
ORM එක සිදු කිරීමට අවශ්‍ය `model` එක සහ `migration` file එක සෑදීමට පහත command එක භාවිතා කල හැක.
```bash
php artisan make:model <model_name> -m
```

දැන් `app/Models/` model class එකට අදාල file එකත් `database/migrations/` වල migration වලට අදාල file එකත් බලාගත හැක.

දැන් `database/migrations/` හි ඇති migration file එක සොයාගෙන එහි පහත කොටසට තමන්ට අවශ්‍ය පරිදි table එකේ columns වෙනස් කරගන්න.
```php
public function up(): void
{
    Schema::create('posts', function (Blueprint $table) {
        $table->id();
        $table->timestamps();
    });
}
```

ඇතුලත් කල හැක columns types මොනවාදැයි බැලීමට [laravel migration documentation](https://laravel.com/docs/migrations#columns) එක භාවිතා කරන්න.

## Make Migration
migration එකක් සිදුකිරීමට පහත command එක භාවිතා කල හැක.
```bash
php artisan migrate
```

## Rollback Migration
සිදුකල migration එකක් නැවත rollback කිරීමට පහත command එක භාවිතා කල හැක.
```bash
php artisan migrate:rollback
```