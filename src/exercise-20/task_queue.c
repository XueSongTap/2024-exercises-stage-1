#include <stdio.h>
#include <stdlib.h>

#include "task_queue.h"

TaskNode *
create_task (int task_id)
{
  TaskNode *new_task = (TaskNode *)malloc (sizeof (TaskNode));
  if (!new_task)
    {
      perror ("Memory allocation failed");
      exit (EXIT_FAILURE);
    }
  new_task->task_id = task_id;
  new_task->next = NULL;

  return new_task;
}

TaskNode *
merge_task_queues (TaskNode *a, TaskNode *b)
{
  if ((!a) || (!b))
    return a ? a : b;

  TaskNode head, *tail = &head, *a_ptr = a, *b_ptr = b;

  while (a_ptr && b_ptr)
    {
      /*
       * 在这里比较 task_id 以调整合并后任务队列的顺序。
       *
       */
      if (a_ptr->task_id < b_ptr->task_id) {
          tail->next = a_ptr;
          a_ptr = a_ptr->next;
      } else {
          tail->next = b_ptr;
          b_ptr = b_ptr->next;
      }
      tail = tail->next;
    }

  tail->next = (a_ptr ? a_ptr : b_ptr);

  return head.next;
}

void
free_task_queue (TaskNode *head)
{
  TaskNode *current = head;
  TaskNode *temp;
  while (current != NULL)
    {
      temp = current;
      current = current->next;
      free (temp);
    }
}

void
print_task_queue (TaskNode *head)
{
  TaskNode *current = head;
  while (current != NULL)
    {
      printf ("%d ", current->task_id);
      current = current->next;
    }
  printf ("\n");
}
