# Cross-Site Scripting (XSS) - Advanced Security Analysis

## Module 0: Course Framing & Real-World Context
### Why XSS Still Dominates in 2025
- Current threat landscape and statistics
- High-profile breaches and their impact
- The cost of XSS vulnerabilities
### Course Prerequisites & Expectations
- Expected knowledge: HTTP, HTML/DOM, JavaScript, basic web security
- Hands-on focus: 60% practical labs, 40% theory
### Legal & Ethical Boundaries
- Authorized testing scope
- Responsible disclosure process
- Bug bounty programs vs. unauthorized testing

---

## Module 1: XSS Taxonomy & Attack Mechanics

### 1.1 The Three Primary Types
**Reflected XSS**
- Attack flow and victim interaction required
- Common contexts: search boxes, error messages, redirects
- Social engineering considerations

**Stored XSS**
- Persistence mechanisms and database storage
- Multi-victim scenarios and worm potential
- Time-delayed exploitation

**DOM-based XSS**
- Client-side vulnerability fundamentals
- Sources and sinks analysis
- Why traditional WAFs miss these
- **Lab 1.1**: Identify DOM XSS sources and sinks in sample code

### 1.2 Beyond the Basics - XSS Variants
- Self-XSS and social engineering amplification
- Mutation XSS (mXSS): when HTML parsers disagree
- Blind XSS: exploitation without immediate feedback
- Universal XSS (UXSS): browser-level vulnerabilities
- **Lab 1.2**: Trigger mXSS through HTML parser inconsistencies

### 1.3 The "Cross-Site" Misnomer & SOP Bypass
- Why XSS is actually a same-origin attack
- How XSS circumvents Same-Origin Policy protections
- The trust boundary violation

---

## Module 2: Injection Points & Context Analysis

### 2.1 Identifying Injection Surfaces
- Beyond obvious inputs: HTTP headers, cookies, referer, file uploads
- Hidden injection points: JSON responses, XML endpoints, SVG files
- WebSocket and postMessage channels
- Third-party script contexts

### 2.2 Context-Aware Payload Crafting
**HTML Body Context**
- Tag injection techniques
- Breaking out of comments and CDATA

**HTML Attribute Context**
- Quote escaping and attribute injection
- Event handler exploitation
- Data attributes and custom attributes

**JavaScript Context**
- String escaping and breaking syntax
- Template literal injection
- JSON injection patterns

**URL Context**
- JavaScript protocol handlers
- Data URIs and blob URLs

**CSS Context**
- Expression() and behavior properties
- @import and url() exploitation
- **Lab 2.1**: Craft payloads for 5 different contexts in a challenge app
- **Lab 2.2**: Context switching - escape one context to inject into another

### 2.3 Browser Behavior Deep Dive
- innerHTML vs innerText vs textContent
- document.write() and its dangers
- eval() and Function() constructor risks
- jQuery sinks ($(), .html(), .append())
- Modern framework pitfalls (React's dangerouslySetInnerHTML, Vue v-html, Angular bypassSecurityTrust)

---

## Module 3: Evasion & Filter Bypass Techniques

### 3.1 Understanding Defense Mechanisms
- Blacklist filters and their weaknesses
- WAF detection and analysis
- Server-side vs client-side filtering
- Browser XSS auditors (deprecated but relevant)

### 3.2 Bypass Arsenal
**Encoding & Obfuscation**
- HTML entity encoding (decimal, hex, named)
- URL encoding variations
- Unicode normalization attacks
- Character set confusion

**Alternative Vectors**
- Tag alternatives: `<svg>`, `<math>`, `<iframe>`, `<object>`, `<embed>`
- Event handler alternatives: 100+ event types
- JavaScript URIs in unexpected places
- CSS-based vectors

**Filter Logic Exploitation**
- Case variation and mixed encoding
- Nested encoding
- Comment injection: `<!-->`, `<!-->`
- Null bytes and special characters
- Polyglot payloads
- **Lab 3.1**: Progressive filter bypass challenges (10 levels)
- **Lab 3.2**: Bypass a simulated WAF using encoding techniques

### 3.3 CSP Bypass Techniques
- JSONP endpoint abuse
- AngularJS sandbox escapes (legacy but educational)
- Script gadgets in whitelisted libraries
- Base-tag injection for relative path hijacking
- Dangling markup injection
- **Lab 3.3**: Exploit a misconfigured CSP policy

---

## Module 4: Weaponization & Post-Exploitation

### 4.1 Session Hijacking
- Cookie theft via `document.cookie`
- HttpOnly bypass attempts (spoiler: generally impossible)
- Session fixation via XSS
- Token exfiltration techniques
- **Lab 4.1**: Build a cookie stealer with out-of-band exfiltration

### 4.2 Advanced Exploitation Techniques
**Keylogging & Form Grabbing**
- Event listener attachment
- Input field monitoring
- Real-time exfiltration

**Phishing & UI Manipulation**
- Fake login overlays
- DOM manipulation for credential harvesting
- Browser notification API abuse

**CSRF via XSS**
- Performing state-changing requests
- Multi-step attack chains
- Privilege escalation scenarios

**Browser & Environment Fingerprinting**
- User-agent, plugins, and screen resolution
- Canvas fingerprinting
- WebRTC IP leakage
- **Lab 4.2**: Create a comprehensive keylogger
- **Lab 4.3**: Execute a CSRF attack chain through XSS
- **Lab 4.4**: Build a browser fingerprinting payload

### 4.3 Establishing Persistence
- BeEF (Browser Exploitation Framework) concepts
- Stored XSS as a backdoor
- Service worker injection
- Persistent WebSocket connections

### 4.4 Blind XSS Exploitation
- Out-of-band detection techniques
- Payload delivery to admin panels
- XSS Hunter and alternatives
- Building custom blind XSS infrastructure
- **Lab 4.5**: Set up blind XSS monitoring and trigger detection

---

## Module 5: Detection & Testing Methodologies

### 5.1 Manual Testing Workflow
**Reconnaissance**
- Spidering and input enumeration
- Parameter pollution testing
- Hidden parameter discovery

**Testing Process**
- Canary value methodology
- Context identification
- Payload delivery and validation
- Browser DevTools for DOM analysis
- Network tab analysis for exfiltration confirmation

### 5.2 Automated Scanning
**Tool Overview**
- Burp Suite: Intruder, Repeater, Scanner modules
- OWASP ZAP active scanning
- Nuclei templates for XSS
- Custom fuzzing with ffuf/wfuzz

**Effective Automation**
- Contextual payload lists
- Reducing false positives
- Combining manual and automated approaches
- **Lab 5.1**: Configure Burp Suite for XSS testing
- **Lab 5.2**: Create custom XSS detection templates

### 5.3 Code Review for XSS
**Source Code Analysis (SAST)**
- Dangerous functions by language
- Data flow analysis (taint tracking)
- Grep patterns and regex for quick wins
- Framework-specific patterns

**Security Code Review Checklist**
- Input points to track
- Sink identification
- Encoding validation
- **Lab 5.3**: Review vulnerable code samples and identify XSS

---

## Module 6: Defense-in-Depth Strategy

### 6.1 The Hierarchy of Controls

### 6.2 Context-Aware Output Encoding (The Foundation)
**HTML Context Encoding**
- Encoding `< > " ' &`
- When and where to apply

**JavaScript Context Encoding**
- Unicode escaping
- JSON encoding considerations

**URL Context Encoding**
- Percent-encoding rules
- Path vs query vs fragment

**CSS Context Encoding**
- Rare but necessary scenarios
- **Lab 6.1**: Implement proper encoding in a vulnerable app

### 6.3 Input Validation & Sanitization
**Validation Strategies**
- Whitelist-based validation
- Type checking and length limits
- Regular expression pitfalls

**HTML Sanitization**
- DOMPurify and alternatives
- Allowed tag/attribute configuration
- Sanitization vs encoding: when to use which
- **Lab 6.2**: Configure DOMPurify for rich text input

### 6.4 Safe APIs & Secure Coding Patterns
**Avoiding Dangerous Functions**
- Never: `eval()`, `innerHTML` with user input, `document.write()`
- Prefer: `textContent`, `setAttribute()`, `createElement()`

**Framework-Specific Protections**
- React: JSX auto-escaping and `dangerouslySetInnerHTML` risks
- Angular: Sanitization service and bypass methods
- Vue.js: `v-html` directive dangers
- Template engines: Handlebars, Jinja2, Twig escaping
- **Lab 6.3**: Audit a React app for unsafe patterns

### 6.5 Content Security Policy (CSP) - Advanced
**CSP Directives Deep Dive**
- `default-src`, `script-src`, `style-src`, `img-src`
- `unsafe-inline` and `unsafe-eval` - why they defeat CSP
- Nonce-based CSP implementation
- Hash-based CSP for inline scripts
- `strict-dynamic` for modern apps

**CSP Reporting**
- Report-Only mode for testing
- Violation reporting endpoints
- Analyzing CSP reports

**Common CSP Mistakes**
- Overly permissive policies
- Whitelist bypass scenarios
- JSONP endpoints in whitelist
- **Lab 6.4**: Design and implement a strict CSP policy
- **Lab 6.5**: Test CSP bypass techniques

### 6.6 Cookie Security & HTTP Headers
- `HttpOnly` flag: preventing JavaScript access
- `Secure` flag: HTTPS-only transmission
- `SameSite` attribute: CSRF mitigation
- `X-Content-Type-Options: nosniff`
- `X-Frame-Options` / `frame-ancestors` (clickjacking prevention)

### 6.7 Web Application Firewalls (WAFs)
- Role in defense-in-depth
- Limitations and bypass techniques
- Virtual patching scenarios
- False sense of security

---

## Module 7: Modern Web Architecture Challenges

### 7.1 Single-Page Applications (SPAs)
- Client-side routing vulnerabilities
- State management and XSS
- Virtual DOM considerations
- API-driven architecture risks
- **Lab 7.1**: Find XSS in a React SPA

### 7.2 XSS in Emerging Technologies
**Mobile WebViews**
- iOS WKWebView and UIWebView
- Android WebView configurations
- Bridge vulnerabilities

**Electron Applications**
- `nodeIntegration` risks
- Context isolation bypasses
- Remote code execution chains

**Progressive Web Apps (PWAs)**
- Service worker injection
- Offline persistence

**WebAssembly & Web Workers**
- New attack surfaces

### 7.3 API & Microservices Architecture
- JSON injection and response manipulation
- GraphQL injection points
- REST API XSS vectors
- **Lab 7.2**: Exploit XSS in a JSON API response

---

## Module 8: Production Detection & Incident Response

### 8.1 Runtime Monitoring
- CSP violation reports analysis
- WAF alert correlation
- Behavioral anomaly detection
- Honeytokens and canary values

### 8.2 Logging & Forensics
- What to log for XSS detection
- Payload reconstruction
- Attack chain analysis
- User impact assessment

### 8.3 Incident Response Playbook
- Confirmation and scoping
- Immediate mitigation steps
- User notification requirements
- Post-incident hardening
- **Lab 8.1**: Analyze logs to reconstruct an XSS attack

---

## Module 9: Bug Bounty & Professional Practice

### 9.1 Hunting Methodology
- Target reconnaissance
- Prioritizing high-value targets
- Automation vs manual testing balance
- Time management strategies

### 9.2 Impact Assessment & Reporting
- CVSS scoring for XSS
- Proof-of-concept best practices
- Effective vulnerability reports
- Communication with security teams
- **Lab 9.1**: Write a professional XSS vulnerability report

### 9.3 Bug Bounty Platforms
- HackerOne, Bugcrowd, Intigriti overview
- Payout expectations and negotiation
- Scope understanding and rules of engagement
- Avoiding duplicate reports

---

## Module 10: Hands-On Capture the Flag

### 10.1 Guided Challenges
- **CTF 1**: Reflected XSS with encoding bypass
- **CTF 2**: Stored XSS in a comment system
- **CTF 3**: DOM XSS via URL fragment
- **CTF 4**: Blind XSS in admin panel
- **CTF 5**: CSP bypass challenge
- **CTF 6**: mXSS through HTML sanitizer
- **CTF 7**: Filter evasion gauntlet
- **CTF 8**: Full-chain exploitation (XSS → Session Hijacking → Account Takeover)

### 10.2 Practice Platforms
- PortSwigger Web Security Academy (XSS labs)
- OWASP WebGoat
- DVWA (Damn Vulnerable Web Application)
- bWAPP
- HackTheBox web challenges
- PentesterLab

---

## Module 11: Advanced Topics & Research

### 11.1 Browser-Level Vulnerabilities
- UXSS through browser bugs
- Extension-based XSS
- PDF XSS and other file format vectors

### 11.2 Combining XSS with Other Vulnerabilities
- XSS + CSRF for complete account takeover
- XSS + Clickjacking combinations
- XSS + Open Redirect chains
- XSS + SSRF for internal network access
- Prototype pollution leading to XSS

### 11.3 Side-Channel Attacks
- Cross-site leaks via XSS
- Timing attacks enhanced by XSS
- Browser API abuse (WebRTC, WebSocket, SharedArrayBuffer)

### 11.4 Research & 0-Day Hunting
- Framework vulnerability research
- Browser quirk discovery
- Mutation testing approaches
- **Lab 11.1**: Research a JavaScript library for XSS gadgets

---

## Module 12: Secure Development Lifecycle Integration

### 12.1 Security Requirements & Threat Modeling
- Identifying XSS risks in design phase
- Security stories and acceptance criteria

### 12.2 Secure Coding Standards
- Organization-wide encoding guidelines
- Code review checklists
- Pre-commit hooks and linting

### 12.3 Security Testing in CI/CD
- SAST integration (Semgrep, SonarQube)
- DAST integration (ZAP, Burp Enterprise)
- Security gates and build failures

### 12.4 Security Training for Developers
- Common mistakes and why they happen
- Framework-specific secure patterns
- **Lab 12.1**: Create a security training module for your dev team

---

## Module 13: Case Studies & Real-World Analysis

### 13.1 High-Impact XSS Vulnerabilities
- **Case Study 1**: MySpace Samy Worm (2005) - First major XSS worm
- **Case Study 2**: TweetDeck XSS (2014) - Self-propagating via retweets
- **Case Study 3**: British Airways (2018) - Magecart supply chain attack
- **Case Study 4**: Modern SaaS platform XSS (recent example)
- **Case Study 5**: Blind XSS in enterprise software

### 13.2 Lessons Learned
- Common root causes across incidents
- Defense gaps that were exploited
- Response effectiveness analysis

---

## Module 14: Resources & Continuous Learning

### 14.1 Essential Reading
- OWASP XSS Prevention Cheat Sheet
- PortSwigger Research Blog
- Security research papers and whitepapers

### 14.2 Payload Collections & References
- PayloadsAllTheThings XSS section
- AwesomeXSS repository
- HTML5 Security Cheatsheet
- Context-specific encoding tables

### 14.3 Community & Practice
- Bug bounty platforms
- CTF competitions
- Security conferences (DEF CON, Black Hat, OWASP AppSec)
- Twitter security researchers to follow

### 14.4 Your Learning Path Forward
- 30/60/90 day practice plan
- Specialization options (mobile, API, browser security)
- Certification paths (OSWE, eWPTX)

---

## Appendices

### Appendix A: XSS Payload Reference
- Comprehensive payload library organized by context
- Encoding cheat sheet

### Appendix B: Tool Configuration Guide
- Burp Suite extensions for XSS testing
- ZAP automation scripts
- Browser extension recommendations

### Appendix C: Secure Coding Checklist
- Language-specific guidelines (JavaScript, PHP, Python, Java, C#, Go)
- Framework-specific patterns

### Appendix D: CSP Policy Templates
- Starter policies by application type
- Migration strategies for existing apps

### Appendix E: Vulnerability Report Template
- Professional disclosure format
- PoC guidelines and ethics
