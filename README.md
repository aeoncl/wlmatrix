# WLMatrix Proof of Concept
The goal is to turn WLM2009 into a Matrix client.

## The plan
1. We need to make the msn client connect to our localhost "server" which will be forwarding MSNP commands to a matrix server.
	- this is mostly done.
2. We need a c++ server which will be turned into a dll and run when the msnmsgr process starts
3. The server needs to :
	- Listen for MSNP Commands (two tcp servers)
	- Listen for SOAP Commands (1 http server)
	- Make REST calls to matrix APIS
	- Serialize & Deserialize JSON and XML (this is my first c++ project so if i can avoid libs & reinvent the wheel i will)
	- Translate MSNP to Matrix & Back
	- Making all of this while not being a tangle mess of everlasting classes :'(
4. Having fun while doing all of the above.

