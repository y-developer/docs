https://blog.logrocket.com/custom-events-in-javascript-a-complete-guide/

## How to create a custom event in JavaScript

custom envet එකක් සෑදිය හැකි ක්‍රම දෙකකි.
- `Event` constructor එක භාවිතයෙන්
- `CustomEvent` constructor එක භාවිතයෙන්

### Event constructor එක භාවිතයෙන්

```javascript
const myEvent = new Event('myevent', {
  bubbles: true,
  cancelable: true,
  composed: false
})
```
**bubbles**

සාදාගත් custom element එක එහි parent සමග සම්බන්ධ විය යුතුද නොවිය යුතුද යන්න මෙමගින් දෙනු ලබයි. වැඩි විස්තර සදහා [Learn JavaScript Event Listeners In 18 Minutes](https://youtu.be/XF1_MlZ5l6M?t=232) බලන්න. සාමාන්‍යයෙන් මෙය වැලැක්වීමට `event.stopPropagation()` function එක භාවිතා කෙරේ. 


### CustomEvent constructor එක

මෙහි ඇති විශේෂත්වය වන්නේ event listern එකට data pass කිරීමේ හැකියාවයි.

```javascript
const myEvent = new CustomEvent("myevent", {
  detail: {},
  bubbles: true,
  cancelable: true,
  composed: false,
});

```

## Dispatching custom events in Javascript

