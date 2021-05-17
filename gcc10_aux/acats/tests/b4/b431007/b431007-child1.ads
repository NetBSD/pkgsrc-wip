

package B431007.Child1 is

   type Ext1 is new B431007.Root with private;

private

   type Ext1 is new B431007.Root with record
      C2 : Integer;
   end record;

   X1 : constant Ext1 := (C1 | C2 => 0);                     -- OK. {26;1}

end B431007.Child1;
