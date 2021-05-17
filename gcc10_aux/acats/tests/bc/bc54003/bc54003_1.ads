

     --===================================================================--


generic
   type Item is private;
   type Index is (<>);                             -- Template for generic
   type Formal_Array is array (Index) of Item;     -- formal package.
package BC54003_1 is end;
