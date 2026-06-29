# CS 305: Software Security - Artemis Financial Portfolio

## Project Overview
This repository contains artifacts from my work analyzing and securing a web application for Artemis Financial. As a consulting company that develops individualized financial plans (including savings, retirement, investments, and insurance), Artemis Financial handles highly sensitive personally identifiable information (PII). The company sought to modernize its operations and required a comprehensive security overhaul. Specifically, they needed an assessment of their current vulnerabilities, the implementation of secure communications (HTTPS/TLS), and a cryptographic data verification step (SHA-256 checksums) to protect client data from external threats.

## Reflection & Security Assessment

**Vulnerability Identification & The Value of Security**
During the initial assessment, I successfully identified several critical architectural flaws within the provided codebase, including Broken Object Level Authorization (BOLA), SQL Injection vectors, and the use of obsolete cryptography (MD5). Identifying these early allowed for a structured remediation plan. Secure coding is not just a technical requirement; it is a fundamental business imperative. For a company like Artemis Financial, robust software security maintains client trust, ensures compliance with federal regulations (like GLBA and FIPS), and protects the organization's overall well-being from catastrophic financial and reputational damage.

**Challenges and Breakthroughs**
The most challenging, yet helpful, part of the vulnerability assessment was mapping the codebase to the Vulnerability Assessment Process Flow Diagram. Transitioning from theoretical security concepts to manually reviewing Java controllers and entity models required deep focus. Uncovering how transitive dependencies (like outdated Spring Boot libraries) could introduce critical flaws like Spring4Shell was a major learning milestone in understanding software supply chain risks.

**Increasing Layers of Security (Defense-in-Depth)**
To secure the application, I implemented a defense-in-depth strategy. I added transport-layer security by generating a self-signed PKCS12 certificate via Java Keytool and enforcing HTTPS. At the application layer, I refactored the code to include a SHA-256 checksum mechanism, ensuring data integrity during transfers. In future projects, I will continue to use a hybrid approach: combining automated Static Application Security Testing (SAST) for dependency mapping with manual architectural reviews to catch logical flaws like authorization bypasses.

**Ensuring Functionality and Post-Refactor Auditing**
To ensure the application remained functional and secure, I ran iterative tests locally, verifying the endpoints (e.g., `https://localhost:8443/hash`) correctly processed the cryptographic logic. To guarantee my refactoring didn't introduce new vulnerabilities, I integrated the OWASP Dependency-Check Maven plugin. When initial scans revealed hundreds of legacy vulnerabilities, I updated the Spring Boot parent version in the `pom.xml` and re-ran the static analysis (`mvn dependency-check:check`) until the vulnerability count was successfully driven down, proving the application was secure.

**Tools and Best Practices for the Future**
Throughout this project, I relied heavily on the OWASP Dependency-Check tool, Maven build configurations, the Java `MessageDigest` libraries, and the National Vulnerability Database (NVD). Moving forward in my Information Security career, integrating automated software composition analysis (SCA) directly into the CI/CD pipeline will be a standard practice for any development environment I contribute to.

**Portfolio Showcase**
I would confidently show future employers my **Practices for Secure Software Report** (included in this repository). It effectively demonstrates my ability to not only identify legacy cryptographic flaws and supply chain vulnerabilities but to actually refactor the Java codebase, deploy modern AEAD standards, and execute automated security testing to validate the fixes.
