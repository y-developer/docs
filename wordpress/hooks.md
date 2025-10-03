# Wordpress hooks

## Core WordPress Hooks

### Initialization & Loading
```php
<?php
add_action('init', 'callback'); 
// Fired after WordPress has finished loading but before headers are sent

add_action('plugins_loaded', 'callback'); 
// All active plugins have been loaded

add_action('after_setup_theme', 'callback'); 
// Theme and functions.php have loaded

add_action('wp_loaded', 'callback'); 
// WordPress, all plugins, and theme are fully loaded
```

### Admin Hooks
```php
<?php
add_action('admin_init', 'callback'); 
// Admin area initialization

add_action('admin_menu', 'callback'); 
// Add admin menu pages and subpages

add_action('admin_enqueue_scripts', 'callback'); 
// Enqueue admin scripts and styles

add_action('admin_notices', 'callback'); 
// Display admin notices/messages

add_action('admin_head', 'callback'); 
// Add content to admin <head> section
```

### Frontend Hooks
```php
<?php
add_action('wp_enqueue_scripts', 'callback'); 
// Enqueue frontend scripts and styles

add_action('wp_head', 'callback'); 
// Add content to <head> section

add_action('wp_footer', 'callback'); 
// Add content before closing </body> tag

add_action('template_redirect', 'callback'); 
// Before template is loaded (redirects, 404s)
```

### User & Authentication
```php
<?php
add_action('user_register', 'callback'); 
// When a new user is registered

add_action('wp_login', 'callback'); 
// When user logs in

add_action('wp_logout', 'callback'); 
// When user logs out

add_action('profile_update', 'callback'); 
// When user profile is updated
```

## WooCommerce Specific Hooks
### Initialization
```php
<?php
add_action('woocommerce_init', 'callback'); 
// WooCommerce is initialized

add_action('woocommerce_loaded', 'callback'); 
// WooCommerce is fully loaded
```

### Payment Gateways
```php
<?php
add_action('woocommerce_update_options_payment_gateways_gateway_id', 'callback'); 
// When payment gateway settings are updated

add_action('woocommerce_api_gateway_callback', 'callback'); 
// Handle payment gateway API callbacks
```

### Order Management
```php
<?php
add_action('woocommerce_new_order', 'callback'); 
// When a new order is created

add_action('woocommerce_order_status_changed', 'callback'); 
// When order status changes

add_action('woocommerce_payment_complete', 'callback'); 
// When payment is completed

add_action('woocommerce_order_refunded', 'callback'); 
// When order is refunded
```

### Checkout Process
```php
<?php
add_action('woocommerce_checkout_process', 'callback'); 
// During checkout validation

add_action('woocommerce_checkout_order_processed', 'callback'); 
// After order is processed

add_action('woocommerce_thankyou', 'callback'); 
// On thank you page
```

### Product Management
```php
<?php
add_action('woocommerce_product_set_stock', 'callback'); 
// When product stock is updated

add_action('woocommerce_reduce_order_stock', 'callback'); 
// When order stock is reduced

add_action('woocommerce_restore_order_stock', 'callback'); 
// When order stock is restored
```

## AJAX & REST API
``` php
<?php
add_action('wp_ajax_action_name', 'callback'); 
// AJAX for logged-in users

add_action('wp_ajax_nopriv_action_name', 'callback'); 
// AJAX for non-logged-in users

add_action('rest_api_init', 'callback'); 
// Initialize REST API endpoints
```

## Email & Notifications
```php
<?php
add_action('woocommerce_email_before_order_table', 'callback'); 
// Before order table in emails

add_action('woocommerce_email_after_order_table', 'callback'); 
// After order table in emails

add_action('wp_mail_failed', 'callback'); 
// When email sending fails
```

## Cron & Scheduled Tasks
```php
<?php
add_action('wp_cron_schedules', 'callback'); 
// Add custom cron schedules

add_action('your_custom_cron_hook', 'callback'); 
// Custom scheduled task
```

## Plugin Lifecycle
```php
<?php
add_action('activate_plugin_name', 'callback'); 
// When plugin is activated

add_action('deactivate_plugin_name', 'callback'); 
// When plugin is deactivated

register_activation_hook(__FILE__, 'callback'); 
// Plugin activation (used with register function)

register_deactivation_hook(__FILE__, 'callback'); 
// Plugin deactivation (used with register function)
```

** Common Priority Usage **
```php
<?php
add_action('init', 'callback', 10); // Default priority
add_action('init', 'callback', 5);  // Higher priority (runs earlier)
add_action('init', 'callback', 20); // Lower priority (runs later)
```
