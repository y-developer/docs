# Github Actions Events

## **`push`**
කෙනෙකු repository එකට commits push කරන විට trigger වේ. Branch එකකට හෝ tag එකකට code යවන විට මෙය ක්‍රියාත්මක වේ.

## **`pull_request`**
Pull request එකක් විවෘත කරන විට, යාවත්කාලීන කරන විට, හෝ merge කරන විට trigger වේ. Code review ක්‍රියාවලියේදී බහුලව භාවිතා වේ.

## **`workflow_dispatch`**
GitHub UI එකෙන් හෝ API එකෙන් manually workflow එකක් ධාවනය කිරීමට ඉඩ දෙයි. අතින් ක්‍රියාත්මක කළ හැකි trigger එකකි.

## **`schedule`**
නිශ්චිත වේලාවකට cron syntax භාවිතයෙන් workflow ස්වයංක්‍රීයව ධාවනය කරයි. නිත්‍ය කාර්යයන් සඳහා භාවිතා වේ.

## **`release`**
Repository එකේ නව release එකක් නිර්මාණය කරන විට හෝ ප්‍රකාශයට පත් කරන විට trigger වේ. Software version නිකුත් කිරීම් සඳහා උපයෝගී වේ.

## **`issue_comment`**
Issue එකක හෝ pull request එකක comment එකක් එකතු කරන විට trigger වේ. සාකච්ඡා සඳහා ප්‍රතිචාර දැක්වීමට භාවිතා වේ.

## **`pull_request_review`**
Pull request එකක් සඳහා review එකක් submit කරන විට trigger වේ. Approve, request changes, හෝ comment කරන විට ක්‍රියාත්මක වේ.

## **`pull_request_review_comment`**
Pull request review එකක විශේෂිත code line එකකට comment කරන විට trigger වේ. Code-specific සාකච්ඡා සඳහා භාවිතා වේ.

## **`repository_dispatch`**
බාහිර සේවාවකින් හෝ API call එකකින් custom event එකක් මගින් workflow trigger කිරීමට ඉඩ දෙයි. බාහිර integration සඳහා භාවිතා වේ.

## **`workflow_call`**
වෙනත් workflow එකකින් reusable workflow එකක් කැඳවන විට trigger වේ. Workflow එකක් අනෙක් එකකින් භාවිතා කිරීමට ඉඩ දෙයි.

## **`create`**
Branch එකක් හෝ tag එකක් නිර්මාණය කරන විට trigger වේ. නව references සඳහා ප්‍රතිචාර දැක්වීමට භාවිතා වේ.

## **`delete`**
Branch එකක් හෝ tag එකක් මකා දමන විට trigger වේ. Cleanup කාර්යයන් සඳහා උපයෝගී වේ.

## **`fork`**
කෙනෙකු repository එක fork කරන විට trigger වේ. Repository එක copy කරන විට ක්‍රියාත්මක වේ.

## **`watch`**
කෙනෙකු repository එක star කරන විට trigger වේ. Repository එකට අනුමත කිරීම් ලබා ගන්නා විට ක්‍රියාත්මක වේ.

## **`issues`**
Issue එකක් විවෘත කරන විට, වසා දමන විට, හෝ වෙනස් කරන විට trigger වේ. Issue management සඳහා භාවිතා වේ.

## **`label`**
Repository එකේ label එකක් එකතු කරන විට, මකා දමන විට, හෝ සංස්කරණය කරන විට trigger වේ.

## **`milestone`**
Milestone එකක් නිර්මාණය කරන විට, වසා දමන විට, හෝ වෙනස් කරන විට trigger වේ. Project tracking සඳහා භාවිතා වේ.

## **`project`**
Project board එකක් හෝ project card එකක් වෙනස් කරන විට trigger වේ. Project management සඳහා භාවිතා වේ.

## **`public`**
Private repository එකක් public කරන විට trigger වේ. Visibility වෙනස් වන විට ක්‍රියාත්මක වේ.

## **`status`**
Commit එකක status check එකක් වෙනස් වන විට trigger වේ. CI/CD status updates සඳහා භාවිතා වේ.

## **`deployment`**
Deployment එකක් නිර්මාණය කරන විට trigger වේ. Deploy ක්‍රියාවලිය ආරම්භ කිරීම සඳහා භාවිතා වේ.

## **`deployment_status`**
Deployment එකක status වෙනස් වන විට trigger වේ. Deploy සාර්ථක හෝ අසාර්ථක බව නිරීක්ෂණය කිරීමට භාවිතා වේ.