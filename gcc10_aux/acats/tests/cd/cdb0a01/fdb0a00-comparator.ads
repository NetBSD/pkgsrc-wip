
---------------------------------------------------------- FDB0A00.Comparator

with System.Storage_Pools;
package FDB0A00.Comparator is

  function "="( A,B : System.Storage_Pools.Root_Storage_Pool'Class )
           return Boolean;

end FDB0A00.Comparator;
