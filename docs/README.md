# Task Queue Research

My name is Eric Navarro and I'm a videogame programmer student at CITM, UPC. This is a research about Task Queues on C++, content that is created for the subject of Project 2 and I will teach you the basics so you can apply them on your own videogame.

## Queues
Queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), where elements are inserted into one end of the container and extracted from the other.+

## Task Queues
Task Queues let applications perform work, called tasks, asynchronously outside of a user request. If an app needs to execute work in the background, it adds tasks to task queues. The tasks are executed later, by worker services.

Task queues come in two flavors, push and pull. The manner in which the Task Queue service dispatches task requests to worker services is different for the different queues.

## Push Queues and Pull Queues

Push queues run tasks by delivering HTTP requests to App Engine worker services. They dispatch these requests at a reliable, steady rate and guarantee reliable task execution. Because you can control the rate at which tasks are sent from the queue, you can control the workers' scaling behavior and hence your costs.

Pull queues do not dispatch tasks at all. They depend on other worker services to "lease" tasks from the queue on their own initiative. Pull queues give you more power and flexibility over when and where tasks are processed, but they also require you to do more process management. When a task is leased the leasing worker declares a deadline. By the time the deadline arrives the worker must either complete the task and delete it or the Task Queue service will allow another worker to lease it.

## Use cases

### Push Queues

One typical push queue use case is a "slow" operation. Consider a social network messaging system. Every time a user sends a message, the network needs to update the followers of the sender. This can be a very time-consuming operation. Using a push queue, the application can enqueue a task for each message as it arrives to be dispatched to a worker service for processing. When the worker receives the task request, it can retrieve the sender's list of followers and update the DB for each one. The worker can be made even more efficient by enqueuing another pushtask for each database update.

### Pull Queues

Pull queues work well when you need to batch tasks together for efficient execution. One solution takes advantage of the ability to attach a tag to a pull task. Workers can lease a group of tasks that have the same tag. A typical example might be an app that maintains leaderboards for numerous different games, with many players and groups constantly in play. Every time there is a new high score, the app can enqueue a pull task with the score and the player, and use the game ID as a task tag. A worker periodically "wakes up", leases a group of tasks with the same game ID, and updates the leaderboard. You can lease tasks explicitly, using a specified tag value, or let the service decide which group of similarly tagged tasks to send.


## Handout


First of all, we have two implemented classes, one that is the first, Task, will serve for the type of task we want to create. In this case we have created a movement task, where we have two virtual methods, one that is the Action () that will serve us to implement the movement for each direction. And another one that is InitTask () that will help us to calculate the final position of the sprite to perform the tasks one after the other when they are finished.

<img src="https://github.com/lakaens/Task-Queue-Research/blob/master/docs/TaskandTaskQueueClasses.PNG" width="300" height="400">

