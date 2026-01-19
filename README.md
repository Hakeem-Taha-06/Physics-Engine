# About
Physics Engine written in C++, this project is made for educational purposes (i'm the one getting educated), it is meant as a learning project where i get to implement and discover code design patterns, which i will document here.

# Patterns used:
- Main loop
- Component systems, where each entity has a std::unique_ptr that points to a collider component.
- Separation Of Concerns (SOC), with a level class that handles game logic, a physics handler that handles collisions, and a ui that handles its own display and logic.
- Update method for each system that can be called easily from the main loop.
- deltaTime implementation.