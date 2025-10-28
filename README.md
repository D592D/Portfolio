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

## The Gaming Room Client - Software Design Document

### Client Overview and Software Requirements

The Gaming Room was a client seeking to expand their existing Android game, "Draw It or Lose It," into a multi-platform web-based application. They wanted a software solution that would allow the game to run seamlessly across multiple operating systems and devices, including Windows, Mac, Linux, iOS, and Android platforms. The game is a puzzle-based competition where teams compete to guess what is being drawn from a rendering library of stock images, with only one instance of the game allowed to exist in memory at any given time. The client required a robust architecture that could support multiple teams and players while maintaining unique identifiers for each entity and ensuring that game instances were properly managed across distributed environments.

### Development Process and Documentation Excellence

In developing the documentation for The Gaming Room, I excelled at creating a comprehensive evaluation of different operating systems and their respective characteristics, providing the client with clear, actionable insights for platform selection. The detailed comparison tables and thorough analysis of server-side, client-side, and development considerations demonstrated a methodical approach to technical communication. Additionally, I effectively articulated the design constraints and system architecture using UML diagrams and clear explanations, making complex technical concepts accessible to both technical team members and non-technical stakeholders.

Working through the design document proved invaluable when developing the actual code implementation. The process of thoroughly analyzing requirements, constraints, and architectural patterns before writing a single line of code provided a clear roadmap for development. By documenting the singleton pattern for game instances, the iterator pattern for managing collections, and the overall domain model structure, I created a reference point that eliminated ambiguity during coding. This upfront planning reduced development time significantly, as design decisions had already been vetted and documented, allowing for focused implementation rather than constant architectural pivoting.

### Areas for Improvement and Revision

If I could revise one aspect of the documentation, I would enhance the recommendations section with more specific implementation timelines and resource allocation estimates. While the technical recommendations were sound, adding projected development sprints, testing phases, and deployment milestones would provide The Gaming Room with better project planning capabilities. I would also include more specific cost-benefit analyses for each platform option, incorporating not just development costs but also maintenance overhead, scalability expenses, and potential revenue impacts. This additional financial context would strengthen the decision-making framework for the client.

### User Needs Analysis and Implementation

Interpreting the user's needs required careful consideration of both the end-users (game players) and the client (The Gaming Room). For players, the design prioritized cross-platform compatibility, responsive performance, and seamless gameplay experience regardless of device. This translated into architectural decisions favoring RESTful APIs, stateless server design, and responsive web technologies. For The Gaming Room as a client, business needs like scalability, security, and maintainability drove the recommendation of Linux-based servers, cloud deployment strategies, and modern development frameworks.

Considering user needs is paramount in software design because software that doesn't serve its intended audience effectively is ultimately a failure, regardless of technical sophistication. User-centered design ensures that technical decisions align with real-world usage patterns, business objectives, and user expectations. By keeping both player experience and client business goals at the forefront, the design balanced performance requirements with cost considerations, creating a solution that was both technically sound and commercially viable.

### Software Design Approach and Future Strategies

My approach to designing this software followed a structured methodology beginning with requirements gathering and stakeholder analysis, progressing through domain modeling and architectural pattern selection, and culminating in platform evaluation and technology recommendations. I employed techniques such as UML modeling to visualize relationships between entities, comparative analysis matrices to evaluate platform options objectively, and design pattern identification to solve common architectural challenges elegantly.

For future software design projects, I would continue using these foundational techniques while incorporating additional strategies such as rapid prototyping to validate architectural decisions early, stakeholder workshops to ensure requirements capture completeness, and risk assessment matrices to identify potential technical and business challenges proactively. I would also emphasize threat modeling earlier in the design process to ensure security considerations are baked into the architecture from the beginning rather than added as an afterthought. Additionally, incorporating performance benchmarking criteria during the design phase would provide measurable targets for implementation success, creating a feedback loop between design decisions and actual system performance.
