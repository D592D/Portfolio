# Corner Grocer — Grocery Frequency Tracker
## Overview / Problem solved
This C++ program reads a plain-text list of grocery items (`CS210_Project_Three_Input_File.txt`), normalizes names, counts how often each item appears, and presents results interactively (lookup, list, histogram). It also writes a backup `frequency.dat`. The tool solves the manual problem of counting occurrences in a list and gives a quick way to inspect item frequency.
## Files
- `main.cpp` — program source (contains `GroceryTracker` class and menu)
- `CS210_Project_Three_Input_File.txt` — input (one item per line)
- `frequency.dat` — generated backup file (item frequency pairs)
- `README.md` — this file
## Build & Run (Windows PowerShell)
1. Compile:
```cmd
g++ main.cpp -o groceryTracker.exe
```
2. Run:
```cmd
.\groceryTracker.exe
```
3. Follow the interactive menu (1=lookup, 2=list, 3=histogram, 4=exit).

---

## What I did particularly well
I demonstrated strong organizational skills by structuring the code with clear separation of concerns—the `GroceryTracker` class encapsulates all data and file I/O logic, while the main function handles user interaction. This modular design makes it straightforward to test individual components and extend functionality without touching the menu flow.

## Where the code could be enhanced
1. **Input validation**: The program currently trusts the input file format. Adding checks for empty lines, special characters, or malformed entries would make it more robust.
2. **Performance**: Using an unordered_map (hash table) instead of map would speed up lookups for very large datasets.
3. **User experience**: Implementing a case-insensitive search so "Apple" and "apple" are treated identically would improve usability.

These enhancements would increase reliability, speed, and ease-of-use without fundamentally changing the existing architecture.

## Most challenging parts and how they were overcome
The histogram generation was initially tricky because it required converting frequency values into a visual representation. I overcame this by breaking the problem into smaller pieces:
1. Iterate through the map
2. Print the item name
3. Use a loop to print asterisks equal to the frequency count

By isolating each step and testing incrementally, I was able to debug effectively and ensure the output aligned with user expectations.

## Tools / resources used
- **C++ Standard Library**: `<map>`, `<fstream>`, `<iostream>`, `<string>` for data structures, file I/O, and console interaction.
- **MinGW-w64 (g++)**: Compiler for building the executable on Windows.
- **VS Code**: Editor for writing and organizing the code.
- **Official C++ documentation**: Reference for map operations and string manipulation functions.

## Transferable skills
- **File I/O**: Reading from and writing to text files is a core skill applicable to data processing tasks in any language.
- **Data structures**: Understanding when to use a map (ordered key-value pairs) versus other containers is fundamental to efficient software design.
- **User interface design**: Building a simple menu-driven console application teaches the basics of user interaction and input validation, which scale to more complex GUI or web-based systems.
- **Incremental development**: Writing and testing small pieces of functionality before integrating them is a best practice in any project.

## Maintainability, readability, adaptability
- **Naming conventions**: Variable and function names are descriptive (`loadItems`, `frequencyMap`, `writeBackupFile`) so another developer can quickly grasp their purpose.
- **Comments**: Inline comments explain non-obvious logic, such as why we convert item names to lowercase.
- **Class encapsulation**: Placing all grocery-tracking logic inside `GroceryTracker` means changes to the data structure or file format only require updates in one place.
- **Modular functions**: Each method in `GroceryTracker` has a single responsibility (e.g., `getFrequency`, `printFrequencies`), making it easy to modify or replace individual features without affecting the rest of the program.

Future developers can extend this code by adding new menu options or changing the data source (e.g., reading from a database) with minimal disruption to existing functionality.

## Next steps (optional)
- Add a graphical user interface (GUI) using a library like Qt or wxWidgets.
- Integrate with a database (SQLite or MySQL) to store and query item frequencies over multiple sessions.
- Implement unit tests using a framework like Google Test to ensure each function behaves correctly.

---

# Sprint Review and Retrospective Reflection

This reflection captures key insights from applying agile and Scrum practices in a recent software development project. Working in an iterative, collaborative environment highlighted the value of regular feedback loops, adaptive planning, and continuous improvement.

## Key Aspects
- **Sprint Planning**: Breaking work into manageable increments helped the team maintain focus and deliver functional software at the end of each sprint.
- **Daily Stand-ups**: Brief daily check-ins kept everyone aligned on progress and surface blockers early.
- **Sprint Review**: Demonstrating completed work to stakeholders ensured we were building the right features and provided opportunities for course correction.
- **Sprint Retrospective**: Reflecting on what went well and what could improve fostered a culture of continuous learning and adaptation.

These practices promoted transparency, accountability, and collaboration—skills that are directly transferable to future projects in any domain.

**Artifact**: [Sprint Review and Retrospective Document](https://github.com/D592D/Portfolio/blob/main/Sprint%20Review%20and%20Retrospective.docx)

---

## The Gaming Room Client - Software Design Document

### Client Overview and Software Requirements
The Gaming Room is a client that requested the expansion of their existing Android game, *Draw It or Lose It*, into a multi-platform web-based application. The game is a team-based drawing competition where players guess what is being drawn within a time limit. The software requirements included:
- Supporting multiple teams and players
- Ensuring unique game and team names
- Providing a web-based interface accessible on various devices and operating systems
- Maintaining a single instance of the game in memory using the Singleton pattern

### Design Constraints and System Architecture Approach
The design had to account for scalability, cross-platform compatibility, and efficient resource management. I recommended a client-server architecture with a RESTful API, allowing the web client to communicate with a central server that manages game state, player sessions, and team coordination. This approach decouples the front end from the back end, enabling independent updates and easier testing. The Singleton pattern was applied to ensure only one game instance existed, preventing conflicts and simplifying state management.

### What I Did Particularly Well in This Documentation
I provided a clear comparison of operating platforms (Windows, Linux, macOS, mobile) and their strengths for hosting the application. By presenting trade-offs in a structured table and explaining the rationale for recommendations, I made it easier for stakeholders to understand technical decisions. I also ensured that UML diagrams and code examples illustrated key design patterns concretely, bridging the gap between abstract concepts and practical implementation.

### How Working Through This Design Document Helped Develop the Code
The design document served as a blueprint, clarifying requirements and architectural decisions before writing code. By identifying design patterns (Singleton, Iterator) and planning the class structure in advance, I avoided rework and ensured that the codebase was modular and maintainable. The document also highlighted potential challenges (e.g., managing concurrent player actions), prompting me to research and integrate appropriate solutions early in the development process.

### Area for Revision and Improvement Strategy
If I could revise one part, I would expand the section on security considerations. While the document addresses authentication and data validation, it could benefit from a more detailed discussion of encryption (TLS/SSL for data in transit), secure session management, and protection against common web vulnerabilities (e.g., SQL injection, cross-site scripting). To improve this, I would:
- Include specific security frameworks and libraries (e.g., OAuth 2.0, bcrypt for password hashing)
- Provide code snippets demonstrating secure coding practices
- Reference industry standards (OWASP Top Ten) to ensure comprehensive coverage

### Interpreting User Needs and Their Importance
I interpreted the user's needs by analyzing the client's goals (expand to multiple platforms, support team-based gameplay, ensure unique identifiers) and translating them into functional and non-functional requirements. For example, the requirement for unique game and team names led to the design of a name-checking mechanism in the game service. Understanding user needs is crucial because software that doesn't align with user expectations or workflows will fail to deliver value, regardless of technical sophistication. By prioritizing usability, scalability, and reliability, I ensured the design would meet both current and future needs.

### Approach to Designing Software and Future Strategies
My approach involved:
1. **Requirements Gathering**: Understanding the client's vision and constraints through careful reading of the project brief.
2. **Research**: Comparing operating systems, development frameworks, and design patterns to identify the best fit.
3. **Modeling**: Creating UML diagrams to visualize relationships between classes and components.
4. **Iterative Refinement**: Revisiting design decisions as new insights emerged during documentation.

In the future, I would incorporate the following techniques:
- **Prototyping**: Building a minimal viable product (MVP) early to validate design assumptions and gather user feedback.
- **User Stories and Use Cases**: Writing detailed scenarios to ensure all user interactions are accounted for.
- **Threat Modeling**: Systematically identifying security risks and mitigation strategies during the design phase.
- **Design Reviews**: Collaborating with peers to critique and improve the design before implementation.

These strategies would help ensure that future projects are not only technically sound but also aligned with user needs and industry best practices.
