

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

package B3A2007_3 is

   FObj : aliased Gen_Tag;
   RObj : aliased Gen_Tag;
   Ren  : Gen_Tag renames RObj;

   GAcc  : ObjFA  := FObj'Access;
   ARen  : RenFA  := Ren'Access;

   -- These declarations are OK in the generic, but won't necessarily be OK
   -- in an instance.

end B3A2007_3;
