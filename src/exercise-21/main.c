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
  char *dup_str = strdup (str);
  char *token = strtok (dup_str, ",");
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
  free (dup_str);
  return head;
}

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s <queue> <k>\n", argv[0]);
      return EXIT_FAILURE;
    }

  int k = atoi (argv[2]);
  TaskNode *queue = create_queue_from_string (argv[1]);

  if (!queue)
    {
      fprintf (stderr, "Failed to create task queue from input\n");
      return EXIT_FAILURE;
    }

  printf ("Original queue: ");
  print_task_queue (queue);

  TaskNode *reversed_queue = reverse_task_queue_by_group (queue, k);

  printf ("Reversed queue: ");
  print_task_queue (reversed_queue);

  free_task_queue (reversed_queue);

  return EXIT_SUCCESS;
}
