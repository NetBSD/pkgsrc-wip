

     --==================================================================--


-- For the generic below, the aliased view X used in X'Access is passed as an
-- actual during instantiation. The accessibility of X is therefore tied to the
-- nesting level of the actual parameter. The access type A of X'Access is
-- also passed as an actual. The nesting level of X must be at least as high
-- (shallow) as that of A.

with B3A2011_0;
generic

   type Gen_Tag is tagged private;

   -- A formal object of a tagged type is aliased.

   type FormalAccType_for_Obj is access constant Gen_Tag;
   An_Obj   : Gen_Tag;

   type FormalAccType_for_Ren is access constant Gen_Tag;
   Ren_Obj  : Gen_Tag;

   type FormalAccType_for_Conv is access constant Gen_Tag;
   Conv_Obj : Gen_Tag;


package B3A2011_1 is

   -- The accessibility level of a derived access type is the same as that
   -- of its ultimate ancestor.

   type New_FormalAccType_for_Obj is new FormalAccType_for_Obj;

   Ren : Gen_Tag renames Ren_Obj;

private

   GAcc1 : FormalAccType_for_Obj     := An_Obj'Access;
   GAcc2 : New_FormalAccType_for_Obj := An_Obj'Access;

   ARen  : FormalAccType_for_Ren     := Ren'Access;
   AConv : FormalAccType_for_Conv    := Gen_Tag(Conv_Obj)'Access;

   -- These declarations are OK in the generic, but won't necessarily be OK
   -- in an instance.

end B3A2011_1;
