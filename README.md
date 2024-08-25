# Socket Communication

This repository contains simple C programs demonstrating basic client-server communication using sockets. The programs include a server and a client that communicate over a network connection.

## Project Overview

- **Server Program (`server.c`)**: A basic server that listens for incoming connections on a specified port. It handles text communication with the client and continues to operate until a "Bye" message is received.
  
- **Client Program (`client.c`)**: A basic client that connects to the server using a specified hostname and port. It sends messages to the server and receives responses. The client terminates when it receives a "Bye" message from the server.

## Prerequisites

- **GCC Compiler**: Ensure you have GCC installed to compile the C programs. You can install it using the following command:

  ```bash
  sudo apt-get install gcc
  ```

- **Network Access**: Make sure that the port you choose is open and not blocked by a firewall.

## How to Compile and Run

### Server

1. **Compile the Server Program:**

   Open your terminal and navigate to the directory containing `server.c`. Run:

   ```bash
   gcc -o server server.c
   ```

2. **Run the Server:**

   Start the server by specifying the port number you want it to listen on:

   ```bash
   ./server <port>
   ```

   Replace `<port>` with the desired port number (e.g., `12345`).

### Client

1. **Compile the Client Program:**

   In the same directory, compile `client.c`:

   ```bash
   gcc -o client client.c
   ```

2. **Run the Client:**

   Start the client by providing the hostname (or IP address) of the server and the port number:

   ```bash
   ./client <hostname> <port>
   ```

   Replace `<hostname>` with the server's address (e.g., `localhost`) and `<port>` with the server's port number.

## Example Usage

1. **Start the Server:**

   ```bash
   ./server 12345
   ```

2. **Start the Client:**

   ```bash
   ./client localhost 12345
   ```

   You can now type messages in the client terminal, which will be sent to the server. The server will respond, and both client and server will continue communication until "Bye" is sent.

## Notes

- Ensure that both server and client are using the same port number.
- The server and client programs are designed for basic testing and demonstration. For production use, consider adding error handling and security features.
- If running on different machines, ensure they are on the same network and the port is open for communication.
