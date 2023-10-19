app.obj: app.c functions.h
	gcc -c app.c -o app.obj
	
additionalfunctions.obj: additionalfunctions.c functions.h
	gcc -c additionalfunctions.c -o additionalfunctions.obj
	
PlayerVsComputer.obj: PlayerVsComputer.c functions.h
	gcc -c PlayerVsComputer.c -o PlayerVsComputer.obj

PlayerVsPlayer.obj: PlayerVsPlayer.c functions.h
	gcc -c PlayerVsPlayer.c -o PlayerVsPlayer.obj
	
	
All: app.obj  additionalfunctions.obj PlayerVsComputer.obj PlayerVsPlayer.obj
	gcc app.obj additionalfunctions.obj PlayerVsComputer.obj PlayerVsPlayer.obj -o out.exe
