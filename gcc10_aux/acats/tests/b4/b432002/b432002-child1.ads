

package B432002.Child1 is

   type Ext1 is new B432002.Root with private;

private

   type Ext1 is new B432002.Root with record
      C2 : Integer;
   end record;

   X1 : constant Ext1 := (B432002.Root with C2 => 0);         -- OK. {26;1}

end B432002.Child1;
