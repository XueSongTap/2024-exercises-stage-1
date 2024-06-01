typedef struct TaskNode
{
  int task_id;
  struct TaskNode *next;
} TaskNode;

TaskNode *create_task (int task_id);

TaskNode *reverse_task_queue_by_group (TaskNode *head, int k);

void free_task_queue (TaskNode *head);

void print_task_queue (TaskNode *head);
