

with B431003_Root;
package B431003_B is
   type Der2 is new B431003_Root.Base with record
      D : Boolean := True;
   end record;

   type Der4 is new B431003_Root.Private_Root with record
      D : Boolean := True;
   end record;

   type Der6 is new B431003_Root.Base with private;
private
   type Der6 is new B431003_Root.Base with record
      D : Boolean := True;
   end record;
end B431003_B;
