### Lab1 - simple commands

mkdir [name] - make directory

mv [old_name] [new_name] - rename
mv [source] [destination] - move

touch [name] - creates an empty file

ln [file] [alias] - creates a hard link
ln -s [file] [alias] - creates a soft link

cp [source] [destination] - copy file to a new destination
cp [name] [new_name] - copy a file in the same directory with a new nme

rm [file] - removes a file

stat [options] [file] - shows metadata of a file
    options:
        -format - can show a custom display of data
            %n - name of the file
            %s - total size
            %a - permissions
            %h - no. of hard links
            %U - name of the owner
            %G - name of the group
            %y - date of last modification

        -c - same as format

chmod [mode] [file] - changes premissions
    modes:
        ugoa (u - owner, g - group, o - others, a - all users)
        421 (4 - read, 2 - write, 1 - execute)
    examples:
        u+x - gives owner exec permission
        g-r - removes group read permission
        a=rwx - gives to all users all permissions

cut -d[delimiter] -f[field_numbers] [file] - extracts fields from text files
    options: --output-delimiter='[delimiter]'

grep [pattern_to_find] [file] - searches for a pattern in the file
    example:
        show info of users with GID 0 in /etc/passwd
            `grep ":0:" /etc/passwd`
        search users with first letter a
            `grep "^a" /etc/passwd`
        search users with first letter from multiple options
            `grep "^[abcd]" /etc/passwd`
        search users with any first letter except
            `grep "^[^abcd]" /etc/passwd`
        search users with last letter from interval a..m
            `grep "[a-m]$" /etc/passwd`


wc [mode] [files] - counts the number of bytes, characters, words and lines
    options:
        -c - number of bytes
        -m - number of characters
        -w - number of words
        -l - number of lines

find [path] [expression] - search for files and directories based on a vast criteria
    path - where the search starts, . for current directory, / for root
    expression:
        -name - searches for files with a specific name
        -iname - case insensitive version of name

        -type - filters by type of file
            f - regular file
            d - directory
            l - symbolic link

        -size - searches by size
            k - kilobytes
            M - megabytes
            G - gibabytes
            b - 512-byte blocks

        + - greater than
        - - less than
  
        -mtime - search based on when a file was modified
        -atime - based on when a file was read/opened
        -ctime - based on when permissions changed
        time is measured in hours (+1 - more than a day, -7 less than 7 days)

        -perm - search by specific permissions
        -user - search for files owned by a specific user
        -group - search for files owned by a specific group

        -print - prints the path
        -delete - deletes file
        -exec [command] - executes path

    examples:
        find ~/Pictures -type f -iname "*.jpg" - finds all jpg in pictures
        find /var/log -type f -size +100M - finds all files with size > 100MB
        find /home -type d -ntime -7 - finds all directories modified in the last 7 days
        find /data -user root -perm 777 - finds all user files with all permissions
        find . -type f \( -name "*.sh" -or -name "*.py" \) - finds all files that are either .sh or .py



### Lab 2 - chain commands

[command] > [file] - creates a file or overwrites it with the new content

[command] >> [file] - appends at the end of the file

head -n [number] [file] - shows first N lines of a file
    example: `head -n 15 /etc/passwd`

tail -n [number] [file] - shows last N lines of a file

ps [options] - displays processes
    options:
        -e or -A - show all processes
        -f - full format
        -o [format] - custom output format
            pid - shows all process id
            user - shows all user names
            comm - shows all command executable names
            args - shows all command lines used to start the process
        -u [user] - shows user processes

sort [options] [file] - sorts the output
    options:
        -r - reverse
        -n - numeric, if not, 10 would be before 2
        -k - sorts by a specific column/field
        -t - defines the delimiter

w - shows users logged in and their remote connection info

tr [options] - translates (replaces) characters
    options:
        [character1] [character2] - replaces character1 with character2
        [sequence1] [sequence2] - replaces sequences
        -d - deletes character
        -s - replaces repeated characters with a single instance

[file] 1> [file] - redirect stdout
[file] 2> [file] - redirect stderr



### Lab 3 - bash scripting

$@ - all parameters
$# - number of parameters
$? - exit status of the last command executed
$1 - first parameter
$2 - second parameter
..

if syntax:
    example:
        if [ condition ] ; then [code] ; fi 
        if [[ condition1 && condition2 ]]
        if [[ condidtion1 || condition2 ]]
        if [ condition1 ] && [ condition2 ]
            if we are using single brackets we need "$var" for null checking
    comparators:
        -eq - equal to
        -ne - not equal to
        -lt - less than
        -le - less than or equal to
        -gt - greather than
        -ge - greather than or equal to
    options:
        -z - checks if parameter is null
        -a - logic and operator
        -o - logic or operator



loop syntax:
    for:
        for (( i=1; i<=n; i++ )) ; do [code] ; done
        for i in `seq 1 $m` ; do [code] ; done
        for i in $(seq 1 $m) ; do [code] ; done
        for variable in item1, item2, item3
        for i in {1..5}

    while:
        i=0
        while (( i < $n )) ; do [code] ; (( i++ )) ; done


arithmmetic methods:
    let var=expr - bash knows to treat var and expr as numbers
    declare -i var - converts var to integer type
    (( var=expr )) - bash standard arithmetic

export [variable] - exports variable to stdout


### Lab 4 - C POSIX files

POSIX (System calls)
    int fd
    open, read, write, close
    <fcntl.h>, <unistd.h>
Standard C Library
    FILE* fp
    fopen, fread, fwrite, fclose
    <stdio.h>

int main(int argc, char* argv[])
    argc - number of parameters
    argv - list of strings (parameters)

scanf([options], [var]) - reads from keyboard
    options:
        "%d"/"%i" - decimal/integer
        "%c" - char
        "%s" - string
        "%f" - float

    - variables need to be referenced (&)

printf([content]) - prints to stdout
    same options as scanf

fprintf(FILE file, [content]) - sends text to any file stream
    best for printing errors
    fprintf(stderr, [error], filename, errno)

open([file_path], [options]) - opens a file
    options:
        O_RDONLY - read only
        O_WRONLY - write only
        O_RDWR - read and write

        then we can add flags with pipe:
        O_CREAT - creates the file if it doesn't exist (requires 3rd parameter: mode)
        O_TRUNC - if the file exists, delete everything inside
        O_APPEND - write data at the end of the file instead of beginning
        O_EXCL - used with O_CREAT, fails if the file already exists
    
    open returns a non-negative integer for success
        -1 otherwise

read([file_descriptor], [buffer], [count]) - reads from a file
    parameters:
        file_descriptor - obtained from a successful open()
        buffer - a bucket where the daa is stored
        count - maximum number of bytes to read in a specific call

    read returns a positive number for success, representing the number of bytes read
        0 if it gets to the end of file
        -1 for failure

write([file_descriptor], [buffer], [count]) - writes to a file
    same parameters and return value as read

close([file_descriptor]) - closes the file

perror([content]) - used for system errors (when open/read/write return -1)

lseek([file_descriptor], [offset], [whence]) - cursor position where the program will read/write
    offset - no. of bytes to move the cursor
    whence - where to move
        SEEK_SET - position cursor at the beginning the of the file
        SEEK_CUR - position cursor at the current position
        SEEK_END - position cursor at the end of the file


### Lab 5 - C files with processes

pid - process id
pid_t - special integer type defined by the system (POSIX)
    we declare a pid_t pid variable before fork to create a workspace where we help the parent track it's children

fork() - the operating system creates a new process (child) by making a copy of the current process (parent)

pid = fork() - pid saves the return value of fork, which is:
    -1 - fail to create process
    0 - pid of the child
    >0 - pid of the parent

wait([status]) - tells the parent process to pause execution until one of its child processes finishes, stops or is terminated 
    status - pointer to an integer where the system can write why the child died
           - can just pass NULL

    wait returns the PID of the child that just finished, -1 otherwise (if the parent has no children to wait)

    we need to use wait to avoid zombie processes (a process that has finished execution but still has an entry in the process table)

waitpid([specific_pid], [status], [options]) - waits for a specific child to finish

exec functions - replace the current process iamge with a new proecss image
execlp([file], [arg0], .., (char *)0) - executes with a list and a path
    file - name of the program (path)
    arg0 - name of the program itself
    0 - must terminate a list with null pointer

    example:
        execlp("ls", "ls", "-l", "/home", (char *)0) - equivalent of ls -l /home

execv([file], [argv]) - executes with a vector of strings
    file - path of the executable
    argv[] - an array of strings, ending with NULL

    example:
        char* args[] = {"ls", "-l", "/home", NULL};
        execv("/bin/ls", args);

execpv([file], [argv]) - it takes an array and searches the path
    example:
        char *args[] = {"ls", "-l", "/home", NULL};
        execpv("ls", args);


### Lab 6 - mmap

#include <sys/mman.h>
#include <sys/stat.h>

fstat([file_descriptor], [stat]) - metadata of a file that is already open
    stat - struct stat st
    if the file is not open, use stat
    can use st_size for file size

ftruncate([file_descriptor], [length]) - set the size of a file to a specific length


mmap([address], [length], [protection], [flags], [file_descriptor], [offset]) - maps a file or device directly into a process's adress space. Instead of using read() or write() you can access file data like an array in memory
    parameters:
        address - usually null
        length - how many bytes of the file to map, usually all of them and you need st.st_size
        protection - memory protection (what you can do with the memory)
            PROT_READ - can read
            PROT_WRITE - can write
            PROT_EXEC - can execute
        flags - controls how updates to the memory are handled
            MAP_PRIVATE - changes local to process and are not saved to file
            MAP_SHARED - changes to memory are written back to the file

munmap([map], [file_size]) - clears out memory





        

    

