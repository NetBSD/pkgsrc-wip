
with B432003;
package B432003_Unrelated is

   type Ext2 is new B432003.Root with record
      C2 : Integer;
   end record;

end B432003_Unrelated;
