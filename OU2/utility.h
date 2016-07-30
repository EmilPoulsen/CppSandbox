#ifndef UTILITY_H
#define UTILITY_H



namespace utility
{

   template <class X> void bubble(X *items,int count)
   {
     X t;

     for(int a=1; a<count; a++)
       for(int b=count-1; b>=a; b--)
         if(items[b-1] > items[b]) {
           t = items[b-1];
           items[b-1] = items[b];
           items[b] = t;
         }
   }
}

#endif // UTILITY_H
