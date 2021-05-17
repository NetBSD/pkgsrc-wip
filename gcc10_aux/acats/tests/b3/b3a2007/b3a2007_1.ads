

     --==================================================================--


-- For the generic below, the aliased view X used in X'Access will be declared
-- within the instance itself. The accessibility of X is therefore tied to the
-- nesting level of the instance. The access type A of X'Access is passed as
-- an actual. The nesting level of X must be at least as high as that of A.

generic

   type Gen_Tag is tagged private;

   type ObjFA is access all Gen_Tag;
   type RenFA is access all Gen_Tag;
   type ConvFA is access all Gen_Tag;

package B3A2007_1 is

   type New_Tag is new Gen_Tag with record
      B : Boolean;
   end record;

   FObj : aliased Gen_Tag;
   RObj : aliased Gen_Tag;
   VObj : aliased New_Tag;
   Ren  : Gen_Tag renames RObj;

   GAcc  : ObjFA  := FObj'Access;
   ARen  : RenFA  := Ren'Access;
   AConv : ConvFA := Gen_Tag(VObj)'Access;

   -- These declarations are OK in the generic, but won't necessarily be OK
   -- in an instance.

end B3A2007_1;
