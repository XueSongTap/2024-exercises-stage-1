typedef struct TaskNode
{
  int task_id;
  struct TaskNode *next;
} TaskNode;

TaskNode *create_task (int task_id);

TaskNode *merge_task_queues (TaskNode *a, TaskNode *b);

void free_task_queue (TaskNode *head);

void print_task_queue (TaskNode *head);
