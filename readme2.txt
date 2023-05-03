Client-Server Calculator
This is a client-server program written in C that implements a simple calculator. The user can input two numbers and an operator (+, -, *, /), and the server performs the calculation and returns the result to the client.

Getting Started


Prerequisites

C compiler (e.g. gcc)
Installation
********************************
1. Clone the repository: git clone https://github.com//client-server-calculator.git
2. Compile the server: gcc server.c -o server
3. Compile the client: gcc client.c -o client
4. Run the server: ./server
5. In another terminal window, run the client: ./client

Usage
****************
1. Enter the first number when prompted.
2. Enter the operator (+, -, *, /) when prompted.
3. Enter the second number when prompted.
4. The server will receive the input, perform the calculation, and return the result to the client.
5. The client will display the result.