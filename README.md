# ft_irc_nonblocking testser

The project tests the 42 school's ft_irc project against blocking file descriptors. If blocking file descriptors are used, then the server should hang and prevent other clients from interacting with the server.

## Build

```make```

## Usage

Run the listener
```
./listener <address> <port> <password>
```
Run the spammer
```
./spammer <address> <port> <password>
```
