### 🧠 **Basic Getters**

| Method                               | Description                                                       |
| ------------------------------------ | ----------------------------------------------------------------- |
| `$order->get_id()`                   | Get the order ID                                                  |
| `$order->get_status()`               | Get the order status (`pending`, `processing`, `completed`, etc.) |
| `$order->get_order_key()`            | Get the unique order key                                          |
| `$order->get_currency()`             | Get the order currency                                            |
| `$order->get_total()`                | Get the total order amount                                        |
| `$order->get_date_created()`         | Returns a `WC_DateTime` object with the creation date             |
| `$order->get_date_modified()`        | Get modified date                                                 |
| `$order->get_payment_method()`       | Get payment method slug (e.g. `fsp_cybersource`)                  |
| `$order->get_payment_method_title()` | Get payment method display name                                   |
| `$order->get_transaction_id()`       | Get transaction ID (useful after payment)                         |

---

### 📋 **Billing & Shipping**

| Method                                                         | Description                     |
| -------------------------------------------------------------- | ------------------------------- |
| `$order->get_billing_first_name()` / `get_billing_last_name()` | Billing names                   |
| `$order->get_billing_email()` / `get_billing_phone()`          | Billing contact                 |
| `$order->get_billing_address_1()` / `get_billing_city()`       | Billing address                 |
| `$order->get_shipping_first_name()` / `get_shipping_city()`    | Shipping fields                 |
| `$order->get_address( 'billing' )`                             | Get full billing address array  |
| `$order->get_address( 'shipping' )`                            | Get full shipping address array |

---

### 🧾 **Order Items**

| Method                           | Description               |
| -------------------------------- | ------------------------- |
| `$order->get_items()`            | Get line items (products) |
| `$order->get_shipping_methods()` | Get shipping line items   |
| `$order->get_coupons()`          | Get coupon items          |
| `$order->get_fees()`             | Get fee line items        |
| `$order->get_taxes()`            | Get tax line items        |

---

### ✍️ **Setters / Updating**

| Method                                   | Description                       |
| ---------------------------------------- | --------------------------------- |
| `$order->set_status( 'completed' )`      | Update order status               |
| `$order->set_transaction_id( 'XYZ123' )` | Set transaction ID                |
| `$order->payment_complete( 'XYZ123' )`   | Mark as paid + set transaction ID |
| `$order->save()`                         | Save the changes to DB            |

---

### 🛠️ **Meta & Custom Data**

| Method                                                    | Description        |
| --------------------------------------------------------- | ------------------ |
| `$order->get_meta( '_your_custom_key' )`                  | Get custom meta    |
| `$order->update_meta_data( '_your_custom_key', 'value' )` | Update custom meta |
| `$order->save_meta_data()`                                | Save meta changes  |

---

### 📌 Example

```php
$order = wc_get_order( 76 );

echo $order->get_status(); // pending
echo $order->get_total();  // 500.00

$billing_email = $order->get_billing_email(); 
$payment_method = $order->get_payment_method();
$items = $order->get_items();

foreach ( $items as $item ) {
    echo $item->get_name() . ' x ' . $item->get_quantity();
}
```
