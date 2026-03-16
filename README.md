# Core-X
I am building this project as I like bulding complex things.Doing this solo is going to be a great adventure👌.
<br><b>Current features:</b>
It is easy to use like console application.
This thing offers passnplay feature where you can play against your friend but need to be a bit focused on what you are moving
where.
It can currently validate if the piece with the turn is moved.
It can currently validate if the piece on target square is friendly piece and give a warning.
Be a bit cautious moving pieces cause it do not offer undo feature.
If you are losing better to resign cause it has that feature.
You can also offer draw if you want and you can only do it after 15 moves.
<br><b>User Manual:</b>
1_Commands:
<br><b>(showboard)</b> This command is the first feature I added into this future engine. By typing this command you are asked for Forsyth Edward Notation(FEN)
that is commonly used to describe positions of many board games.You just copy and paste this notation into it and it automatically
convert that weird but easy and useful FEN into visual board. Than you are free to do what you pasted for.
<br><b>(countpiece)</b> If you are feeling tired to count piece value on board, than this command got you. Simply paste this command into welcome screen and 
it will ask you for Forsyth Edward Notation(FEN) and just copy paste this notation into it and it will automatically calulate pieces and return you the
calculated number of black and white pieces.
<br><b>(cls)</b> Most useful and interesting command just type into console and it will wipe out all the screen and cleans everything on console for you.
<br><b>(passnplay)</b> Most hard thing before many things. Currently under development but you can use it how you play on a chess board but no take back and castling(It is planned for future).
This command opens up a start game window and you can just start playing.If you are real chess player than it is just a simple play game but I also got you if you are a learner or even the one who is not
familiar with chess notations. Remember, in almost all board games colomns are denoted by alphabet letters and rown are described as numerical numbers.
Simply type the current piece location like e2 mean it is 5th colomn and 2nd row. Simply type it and add a space and add the location of target square as you added
current piece location. Always remember in chess it is always white to move first. So the first row is actually the last row on screen.
Capital letters represent white pieces and small letters represents black pieces. If in between you want the current postition FEN then simply type <b>(fen)</b> on your turn and it will return you
the FEN. Want to give up simply type <b>(resign)</b>.Brain is not braining of both you and your friend simply type <b>(abort)</b> to quit the game without any desicion. Feeling you are not going to win,
simply type<b> (draw)</b> and pray if opponent accepts.But remeber you must have played over fifteen moves and if opponent declines, then you are not going to offer any, till next fifteen moves.
Kinda crazy but my work my rules!!!!
<br><b>Future plans:</b>
Will add move validation so that no one can do whatever he/she want.Currently all move functions are totally done just mighty king is waiting to follow my rules.<br>
Will add current position analysis on the bases of piece placement.<br>
It will play one day and this day is not too far, maybe intelligent play should take time.<br>
<b>Developers Roadmap:</b>Hola developers! So I hope you have succesfully learnt what this thing is and how it is working. And now I want you to contribute and show you just do not understand coding but you
but you also understand coding a mind playing mind game. Now there exist many functions for you ease. one function is to to_2D that converts a 1d array to a 2 dimensional array. This is useful as my small mind
can only understand the things happening on board in 2d and it proved helpful for me. But I am giving a sacrifice on its speed. Use of two dimensional arrays will drastically deprove performance. By my 
calculations we can reach a par 5k to 10k moves per second while word number array based engines reach a peak 40 to 50 million moves per second while bitboard operated engine reach a peek of 3 to 4 billion move per second.
Another function to exist is to_1d that works by converting a 2d array into one dimensional array and all these array is a board. The most powerful function is the FEN generator. All the engines in the world 
works on the bases of FEN and it is for mostly board games not only chess. By the way I liked you confidence that you can contribute and do not even know about FEN. So whatever, now the next roadmap is to make
a function that takes the board postition in form of FEN and the square and checks wether this square is attacked or not as this function useful to know if the king is checkmated or castling is possible or not
after it we will build a function that will take the board and will evaluate position, It will not only evaluate on the bases of number of piece and its value but we will include modern table databases that 
will give a piece a value on the bases of where it is place and how much squares it is controlling and will deduct scores if squares near the king are attacked, so the function I discussed earlier is useful.
As we will be done with it we will convert all the array arithmetics to pointer arithmetics pushing our engine calcuation to +500 to +600. Now after all that we introduce and will work on building the self 
playing engine as we have all the necessary plates to cook. So at last this is for the braves😂.
If you are someone waiting to play or test this out or submit this as your school project, we are with you carry on._

