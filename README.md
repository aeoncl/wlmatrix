# WLMatrix

A translation layer between MSNP18 and the Matrix Protocol.

![WLMatrix logo](https://i.imgur.com/62Rx1Fq.png)

## Description

WLMatrix is a TCP/Soap server and a Matrix client.
It translates the commands & requests from Windows Live Messenger to the Matrix Protocol.

## Current state

🟢 Patching WLM to allow it to connect to localhost without using ssl.

🟢 Authentication

> The typical @name:homeserver syntax of matrix cannot work with wlm. The email syntax is used instead : {name@homeserver-port}.

🟠 Fetch contact lists (joined rooms & invites) (MSN: /AbServices.asmx/FindMembership & getContactsPaged <-> Matrix: sync endpoint)

🔴 Everything else
	

## Dependencies

- cpprestsdk
- boost libraries
- magic enum 
- pugixml 


## Special Thanks

Thanks a lot to the Escargot team for all their hard work & compilation of great resources.

Thanks to the people from 2005 that had msnp packets in their .pcap without noticing it
