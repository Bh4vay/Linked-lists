#include <stdio.h>
#include "sll.h"

int
main ()
{
  LINKED_LIST ll;
  Create_LL (&ll);

  InsertAtBeg_LL (&ll, 10);
  InsertAtBeg_LL (&ll, 20);
  InsertAtPos_LL (&ll, 0, 30);
  InsertAtPos_LL (&ll, 1, 40);

  Print_LL (&ll);

  DeleteAtPos_LL (&ll, 1);
  DeleteAtBeg_LL (&ll);

  Print_LL (&ll);

  return 0;
}
