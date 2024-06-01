#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task_queue.h"

#ifndef _GNU_SOURCE
char *
strdup (const char *s)
{
  size_t len = strlen (s) + 1;
  char *dup = malloc (len);
  if (dup)
    {
      strcpy (dup, s);
    }
  return dup;
}
#endif

TaskNode *
create_queue_from_string (const char *str)
{
  TaskNode *head = NULL, *tail = NULL;
  char *token = strtok (strdup (str), ",");
  while (token)
    {
      int task_id = atoi (token);
      TaskNode *new_task = create_task (task_id);
      if (!head)
        {
          head = new_task;
          tail = new_task;
        }
      else
        {
          tail->next = new_task;
          tail = new_task;
        }
      token = strtok (NULL, ",");
    }
  return head;
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <queue1> <queue2>\n", argv[0]);
      return EXIT_FAILURE;
    }

  TaskNode *queue_a = create_queue_from_string (argv[1]);
  TaskNode *queue_b = create_queue_from_string (argv[2]);

  if (!queue_a || !queue_b)
    {
      fprintf (stderr, "Failed to create task queues from input\n");
      return EXIT_FAILURE;
    }

  printf ("Original queues:\n");
  printf ("Queue a: ");
  print_task_queue (queue_a);
  printf ("Queue b: ");
  print_task_queue (queue_b);

  TaskNode *merged_queue = merge_task_queues (queue_a, queue_b);

  printf ("Merged Queue: ");
  print_task_queue (merged_queue);

  free_task_queue (merged_queue);

  return EXIT_SUCCESS;
}
