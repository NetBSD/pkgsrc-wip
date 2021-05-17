

     --==================================================================--


-- For the generic below, the aliased view X used in X'Access will be declared
-- within the instance itself. The accessibility of X is therefore tied to the
-- nesting level of the instance. The access type A of X'Access is passed as
-- an actual. The nesting level of X must be at least as high (shallow) as
-- that of A.

with B3A2008_0;
generic

   type Gen_NewTag is new B3A2008_0.Tagged_Rec with private;
   type FormalAccType_for_Obj is access all Gen_NewTag;

   type Gen_NewRec is new B3A2008_0.Rec;
   type FormalAccType_for_Comp is access all Gen_NewRec;
   type FormalAccType_for_Deref is access all Gen_NewRec;

package B3A2008_1 is

   -- The accessibility level of an aliased component is that of the enclosing
   -- composite *object*, not that of the enclosing composite type.

   type Rec_With_Comp is record
      C : aliased Gen_NewRec;        -- Aliased component of a composite type.
   end record;

   type LocalAccType is access all Gen_NewRec;

   Gen_Obj   : aliased Gen_NewTag;
   Gen_Rec   : Rec_With_Comp;
   Gen_Deref : LocalAccType := new Gen_NewRec;

private

   AObj   : FormalAccType_for_Obj   := Gen_Obj'Access;
   AComp  : FormalAccType_for_Comp  := Gen_Rec.C'Access;
   ADeref : FormalAccType_for_Deref := Gen_Deref.all'Access;


   -- These declarations are OK in the generic, but won't necessarily be OK
   -- in an instance.

end B3A2008_1;
