
with B432002_Unrelated;
with B432002.Child1;
package B432002.Child2 is

   type Ext3 is new B432002.Child1.Ext1 with private;

   type Ext4 is new B432002_Unrelated.Ext2 with private;

   type Ext5 is new B432002.Root with private;

   type Ext6 is new B432002.Root with record
      C2 : Integer;
   end record;

   procedure Force_Body;

private

   type Ext3 is new B432002.Child1.Ext1 with record
      C3 : Integer;
   end record;

   type Ext4 is new B432002_Unrelated.Ext2 with record
      C3 : Integer;
   end record;

   type Ext5 is new B432002.Root with record
      C2 : Integer;
   end record;

   X3 : constant Ext5 := (B432002.Root with C2 => 0);         -- OK. {26;1}

   X4 : constant Ext6 := (B432002.Root with C2 => 0);         -- OK. {26;1}

end B432002.Child2;


