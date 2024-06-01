#include "task_queue.h"
#include <stdio.h>
#include <stdlib.h>

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
reverse_task_queue_by_group (TaskNode *head, int k)
{
  TaskNode *hair = create_task (0);

  /* 用于辅助暂存任务队列 */
  hair->task_id = 0;
  hair->next = head;

  /* 标记翻转前的任务节点 */
  TaskNode *pre = hair;

  while (head != NULL)
    {
      /*
       * TIP
       * 按每 k 个节点一组翻转任务队列。可以利用一个指向头节点 head 的辅
       * 助节点 hair，用 pre 指向 hair。遍历链表，每次移动 k 个节点并翻
       * 转，翻转后的段首与 pre 相连，段尾与下一段相连。继续更新 pre 和
       * head，直到遍历完成。最后返回 hair 的下一个节点作为新头节点。
       */
      TaskNode *tail = pre;

      for (int i = 0; i < k; ++i)
        {
          tail = tail->next;
          if (tail == NULL)
            {
              // 在这里填写代码
            }
        }

      TaskNode *next = tail->next;
      TaskNode *prev = tail->next;
      TaskNode *p = head;

      while (prev != tail)
        {
          TaskNode *temp = p->next;
          // 在这里填写代码
        }

      pre->next = tail;

      // 在这里填写代码

      head = next;
    }

  return hair->next;
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
