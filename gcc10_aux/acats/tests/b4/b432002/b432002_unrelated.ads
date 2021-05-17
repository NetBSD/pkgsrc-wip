
with B432002;
package B432002_Unrelated is

   type Ext2 is new B432002.Root with private;

private

   type Ext2 is new B432002.Root with record
      C2 : Integer;
   end record;

   X2 : constant Ext2 := (B432002.Root with C2 => 0);         -- OK. {26;1}

end B432002_Unrelated;
