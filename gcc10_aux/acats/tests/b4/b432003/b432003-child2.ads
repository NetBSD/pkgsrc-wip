
with B432003_Unrelated;
with B432003.Child1;
package B432003.Child2 is

   type Ext3 is new B432003.Child1.Ext1 with record
      C3 : Integer;
   end record;

   type Ext4 is new B432003_Unrelated.Ext2 with record
      C3 : Integer;
   end record;

   type Ext5 is new B432003.Root with null record;

end B432003.Child2;
