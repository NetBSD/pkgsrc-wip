
with B393011_P;
package B393011_Q is
   type T is abstract new B393011_P.I with private;
   -- Op[1] inherited here as abstract.
   package Inner is
      procedure Inner_Op1 (X : T) renames Op;           -- OK.
         -- Inner_Op1 is abstract, which is OK as it is not primitive for T.
   end Inner;
private
   type T is new B393011_P.I with null record;
   procedure Op (X : T) is null;       -- Op[2]
end B393011_Q;
