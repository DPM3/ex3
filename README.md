# Advanced Programming Excercise 3 (in the works still)


## Cache Structure:

We implemented the cache by creating a mini cache for each operation type.
Each mini cache has a folder manager.
The folder manager is responsible for adding and removing files from the folder given to it.
The folder manager has a sort of queue (implemented a bit differently because it has a fixed size), to keep the folder's size in control.
The folder manager also uses this queue to save the file names in the folder.
The mini cache saves each result in a file, called after the hash (sha1 algorithm) of the operation.
This makes it easy to find the file related to the operation later on.

## How We Read Commands:

We made a parser to read commands.
The parser receives an array of tokens and determines the type of the command, it's arguments and it's output directory.
The parser the returns an OperatorID containing all of the command's info.

## How We Run Commands:

We call the cache manager's runOp function with the command's OperationID as an argument.
The command's OperatorID contains all the info to run the command succesfully.
If the command is a cache clear command it runs immediately.
If the command is a cache search commend then the command get's reparsed without the first 2 tokens,
and then the returned OperationID is passed as an argument to isInCache function.
If the command is a different command then the cache manager checks if the operation is already in cache.
If the operation is already in the cache then it copies the result to the output file, and if not then the result is
calculated with the proper function from the calc namespace and added to the cache.
