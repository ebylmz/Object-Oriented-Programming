JC = javac
R = java
Packet = pegsolitaire
JFlags = 

muo:
	$(JC) $(JFlags) $(Packet)/*.java
	$(R) $(Packet).TestPegSolitaire

javadoc:
	javadoc -d doc/ $(Packet)/*.java

rebuild: clean muo

clean:
	rm -rf $(Packet)/*.class doc/ 