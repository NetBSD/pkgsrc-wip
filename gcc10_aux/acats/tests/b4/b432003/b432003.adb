

with B432003_Unrelated;
with B432003.Child1;
with B432003.Child2;
package body B432003 is

   generic
      type Form1 (<>) is tagged private;
   package Gen1 is
      type Ext6 is new Form1 with record
         C6 : Integer;
      end record;

      XG1 : Ext6 := (Form1 with C6 => 1);                   -- ERROR: {21;1}

      XG2 : Ext6 := (Form1 with others => <>);              -- ERROR: {21;1}
   end Gen1;

   generic
      type Form2 (<>) is new Root with private;
   package Gen2 is
      type Ext7 is new Form2 with record
         C7 : Integer;
      end record;

      XG3 : Ext7 := (Form2 with C7 => 1);                   -- ERROR: {21;1}

      XG4 : Ext7 := (Form2 with others => 0);               -- ERROR: {21;1}
   end Gen2;

   type Ext8 is new B432003.Child2.Ext3 with record
      C4 : Integer;
   end record;

   type Ext9 is new B432003.Child2.Ext4 with record
      C4 : Integer;
   end record;

   type ExtA is new B432003.Child2.Ext5 with null record;

   X01 : constant Ext8 :=
      (B432003.Root with others => 0);                      -- ERROR: {7;1}
      -- The view of Root from which Ext3 is descended has
      -- unknown discriminants.

   X02 : constant Ext8 :=
      (B432003.Child1.Ext1 with C3 | C4 => 0);              -- ERROR: {7;1}
      -- Ext1 inherited unknown discriminants from Root, and we're not
      -- in the immediate scope of Ext1.

   X03 : constant Ext8 :=
      (B432003.Child2.Ext3 with C4 => 0);                   -- ERROR: {7;1}
      -- Ext3 inherited unknown discriminants from Ext1 (which got them from
      -- Root), and we're not in the immediate scope of Ext3.

   X11 : constant Ext9 :=
      (B432003.Root with others => 0);                      -- ERROR: {7;1}
      -- The view of Root from from which Ext4 is descended has
      -- unknown discriminants.

   X12 : constant Ext9 :=
      (B432003_Unrelated.Ext2 with others => 0);            -- ERROR: {7;1}
      -- Ext2 inherited unknown discriminants from Root, and we're not
      -- in the immediate scope of Ext2.

   X13 : constant Ext9 :=
      (B432003.Child2.Ext4 with C4 => 0);                   -- ERROR: {7;1}
      -- Ext4 inherited unknown discriminants from Ext2 (which got them from
      -- Root), and we're not in the immediate scope of Ext4.

   X21 : constant ExtA :=
      (B432003.Root with others => <>);                     -- ERROR: {7;1}
      -- The view of Root from from which Ext5 is descended has
      -- unknown discriminants.

   X22 : constant ExtA :=
      (B432003.Child2.Ext5 with null record);               -- ERROR: {7;1}
      -- Ext5 inherited unknown discriminants from Root, and we're not in
      -- the immediate scope of Ext5.


   -- Note: It doesn't make sense to allow the ancestor of an aggregate
   -- (which is default-initialized) to have a type if a default-initialized
   -- stand-alone object would be illegal.

   X90 : B432003.Child2.Ext5;                               -- ERROR: {4;1}
   X91 : B432003.Child2.Ext4;                               -- ERROR: {4;1}
   X92 : B432003.Child2.Ext3;                               -- ERROR: {4;1}
   X93 : B432003_Unrelated.Ext2;                            -- ERROR: {4;1}
   X94 : B432003.Child1.Ext1;                               -- ERROR: {4;1}
   X95 : B432003.Root;                                      -- OK.    {4;1}
       -- Note: We can see the full view of Root here, but none of
       -- Ext1 through Ext5 are descended from the full view.

   procedure Force_Body is
   begin
      null; -- Force this package to have (and allow) a body.
   end Force_Body;

end B432003;
