

     --==================================================================--


-- For the generic below, the aliased view X used in X'Access is passed as an
-- actual during instantiation. The accessibility of X is therefore tied to the
-- nesting level of the actual parameter. The access type A of X'Access is
-- also passed as an actual. The nesting level of X must be at least as high
-- (shallow) as that of A.

with B3A2012_0;
generic

   type Gen_Tag is tagged private;

   type FormalAccType_for_Obj is access constant Gen_Tag;

   -- A formal object of a tagged type is aliased.
   An_Obj    : Gen_Tag;

   type FormalAccType_for_Comp is access constant Gen_Tag;
   Comp_Obj  : Gen_Tag;

   type FormalAccType_for_Derf is access constant Gen_Tag;
   Derf_Obj  : Gen_Tag;

package B3A2012_1 is

   type New_FormalAccType_for_Obj is new FormalAccType_for_Obj;

   GAcc1 : FormalAccType_for_Obj     := An_Obj'Access;
   GAcc2 : New_FormalAccType_for_Obj := An_Obj'Access;
   AComp : FormalAccType_for_Comp    := Comp_Obj'Access;
   ADerf : FormalAccType_for_Derf    := Derf_Obj'Access;

   -- These declarations are OK in the generic, but won't necessarily be OK
   -- in an instance.

end B3A2012_1;
