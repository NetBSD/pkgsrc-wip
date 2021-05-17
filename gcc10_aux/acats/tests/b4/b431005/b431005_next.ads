
with B431005_Base; use B431005_Base;
package B431005_Next is

   pragma Default_Storage_Pool (null);

   type T2 is new T1 with record
      F2 : access Integer;
   end record;

end B431005_Next;
