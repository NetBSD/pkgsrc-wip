

     --==================================================================--


with B840001_0;
package B840001_1 is

   type My_Tag is tagged record
      C : Integer;
   end record;

   -- Equality operators (=, /=) implicitly declared here.

   Tag01 : My_Tag := (C => 1);
   Tag02 : My_Tag := (C => 2);

   -------

   type Derived_Tag is new My_Tag with null record;

   -- Equality operators (=, /=) implicitly declared here.

   Der01 : Derived_Tag := (C => 1);
   Der02 : Derived_Tag := (C => 2);

private

   use type B840001_0.My_Integer;                                     -- OK.
             -- The effects of this clause are tested in B840001_1.B840001_3
             -- and in B840001_1.B840001 below.
end B840001_1;
