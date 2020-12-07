# WLMatrix
A translation layer between MSNP18 and the Matrix Protocol
making WLM 2009 a Matrix client while keeping all of it's functionality.

![WLMatrix logo](https://i.imgur.com/62Rx1Fq.png)

## How it will work
WLMatrix is a TCP/Soap server and a Matrix client that runs in the background when WLM starts.
It translates the commands & requests from MSNP to the Matrix Protocol.
It's stateless.

## Current state
🟢 Client patch to connect to WLMatrix (will create a different repo for that stuff)

🟠 Authentication (from MSN -> Matrix) kinda working, need to clean up implementation to handle error codes. The typical @name:homeserver synthax of matrix cannot work with wlm, i use this special one instead : {name@homeserver-port} when the port is ommited, 443 will be default.

🟠 Fetch contact lists (joined rooms & invites) (MSN: /AbServices.asmx/FindMembership & getContactsPaged <-> Matrix: sync endpoint)

🔴 Everything else
	
## Special Thanks
Thanks a lot to the Escargot team for all their hard work & compilation of great resources. It helps a lot.
