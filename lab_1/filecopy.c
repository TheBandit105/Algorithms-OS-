/* filecopy: copy file ifp to file ofp */ 
#include <stdio.h>
void filecopy(FILE *ifp, FILE *ofp)
{
   int c;
   while ((c = getc(ifp)) != EOF)
     putc(c,ofp);
}
