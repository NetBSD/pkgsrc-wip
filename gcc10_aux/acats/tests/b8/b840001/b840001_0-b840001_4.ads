

     --==================================================================--


with B840001_1;
package B840001_0.B840001_4 is

   use type B840001_1.Derived_Tag;
   
   DerEqual : Boolean := (B840001_1.Der01 = B840001_1.Der02);         -- OK.
                                                         -- "=" use-visible.

   type Der_Tag is new B840001_1.My_Tag with null record;

   function Tag_Op (P: Der_Tag) return Integer;

   DerObj : Der_Tag := (C => 3);

   type Another_Integer is new My_Integer;

   -- Equality operators (=, /=) implicitly declared here.
   -- Ordering operators (<, <=, >, >=) implicitly declared here.
   -- Binary adding operators (+, -) implicitly declared here.
   -- Unary adding operators (+, -) implicitly declared here.
   -- Multiplying operators (*, /, mod, rem) implicitly declared here.
   -- Highest precedence operators (abs, **) implicitly declared here.

   -- function Int_Op return Another_Integer implicitly declared here.


   Another01 : Another_Integer := 1;
   Another02 : Another_Integer := 2;

end B840001_0.B840001_4;
