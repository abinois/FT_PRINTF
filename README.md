<pre>
----------------------------------------------------------------

   ._____,   ._____,     ._. .__,      ._. ._______. .______,  
   | ._,  \  | ._,  \    |_| |   \     | | |__. .__| | .____|  
   | |  \  | | |  \  |   ._. | |\ \    | |    | |    | |       
   | |   | | | |   | |   | | | | \ \   | |    | |    | |__.    
   | |__/ /  | |__/ /    | | | |  \ \  | |    | |    | .__|    
   | .___/   |  ___ \    | | | |   \ \ | |    | |    | |       
   | |       | |   \ \   | | | |    \ \| |    | |    | |       
   | |       | |    \ \  | | | |     \   |    | |    | |       
   |_|       |_|     \_\ |_| |_|      \__|    |_|    |_|     

----------------------------------------------------------------

This project's purpose is to remake the standard printf function of the stdlib.
Check out the school's Subject.pdf file for more infos.

It is litteraly the same, but with bonuses such as :

%@		-> to secify the file descriptor of the file in wich it will write.
*		-> to get the precision or the field in a argument.
{color}	-> to open a color.
%b...	-> option to write in binary.

Classic converters %d, %i, %o, %u, %x, %X, %p, %f, %s, %c are supported,
with the options : l, L, ll, h, hh, #, -, +, field and precision.

examples :
 - ft_printf("%@Hello World\n", 2);
	-> will write in stderr.
 - ft_printf("%*.*s\n", 45, 25, "Hello World");
	-> will write the string "Hello World" with 45 of field qnd 25 of precision.
 - ft_printf("%bd\n", 5);
 	-> will write : "00000000 00000000 00000000 00000101".
 - ft_printf("{orange}{under}Hello World{reset}\n");
 	-> will write "Hello World" underlined and in orange.
	color options list :
		- red / green / blue / cyan / yellow / black / magenta
		  orange / pink / purple / kaki / grey
		- under		(underline)
		- over		(line through text)
		- bold		(put in bold)
		- italic	(put in italic)
		- blink 	(blink text, if enable in terminal preferences)
		- rev		(reverse the color -> white on black : black on white)
		- reset		(close all and set to default : white)

This project has been done by abinois & edillenb.
👌 enjoy:)
</pre>
