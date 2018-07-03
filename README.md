# Heron Shell
A new shell for linux. The idea is that I will remove the need for the medieval bash control
structures by replacing them with builtin commands.

so if you want to iterate over all files in a directory you could go:
` files | extract name | for | echo `

## Parsing
ok pretty obvious, each first word is the command name and each one after that is an argument.
When it bumps into `|` or `;` of `EOF`, it means that we have reached the end of a bit, and this bit
can hypothetically be immeadiately executed.

If you have a pipe right at the start of your line it means that is a command segment in it's own
right, all it means is that stdout is written to stdin.

ok actually, if a pipe happens at the end of a command then this means it must be saved to some
temporary location, and then after the command line has been entered (which uses stdin) we can
then write the temporary stuff to stdin.

If you are executing a file with multiple lines in it you always need to include `;` between lines
or sections, as things can spread between lines and new lines will basically just be completely
removed. Therefore, `;` is the only thing that seperates command lines.

I would also like to add curly brackets for making a group of command sections that will get
piped the same stuff, mostly for use within loops.
