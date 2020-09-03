# Advanced Programming Excercise 3 (in the works still)


## Cache Structure:

We implemented the cache by creating a mini cache for each function.
Each mini cache has a folder manager.
The folder manager is responsible for adding and removing operations from the mini cache.
The folder manager has a sort of queue (implemented a bit differently because it has a fixed size).
The folder manager uses this queue to save the operations.

## How We Read Commands:

We made a parser to read commands.
The parser receives an array of tokens and determines the command, it's arguments and it's outpuut directory.
The parser the returns an OperationID containing all of the command's important info.

## How We Run Commands:

We call the cache manager's runOp function with the command's OperationID as an argument.
The command's OperationID contains all the info to run the command succesfully.
If the command is a cache clear command it runs immediately.
If the command is a cache search commend then the command get's reparsed without the first token
	and then the returned OperationID is passed as an argument to isInCache function.
If the command is a different command then the cache manager checks if the operation is already in cache.
	If the operation is already in the cache then it returns the result and if not then the result is
	calculated with the proper function from the calc namespace and added to the cache.
