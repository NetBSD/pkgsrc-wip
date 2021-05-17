

     --==================================================================--


with FC51B00;   -- Indefinite subtype declarations.
with CC51B03_0; -- Generic package declarations.
with CC51B03_1;

with Report;
procedure CC51B03 is

   --
   -- Instances for formal private type with unknown discriminants:
   --

   package PrivateFormal_UndiscriminatedTaggedActual is new
     CC51B03_0.PrivateFormalUnknownDiscriminants (FC51B00.Vector);

   package PrivateFormal_ClassWideActual is new
     CC51B03_0.PrivateFormalUnknownDiscriminants (FC51B00.Vector'Class);

   package PrivateFormal_DiscriminatedTaggedActual is new
     CC51B03_0.PrivateFormalUnknownDiscriminants (FC51B00.Square_Pair);

   package PrivateFormal_DiscriminatedUndefaultedRecordActual is new
     CC51B03_0.PrivateFormalUnknownDiscriminants (FC51B00.Square);


   subtype Length is Natural range 0 .. 20;
   type Message (Len : Length := 0) is record   -- Record type with defaulted
      Text : String (1 .. Len);                 -- discriminant (definite).
   end record;
      
   package PrivateFormal_DiscriminatedDefaultedRecordActual is new
     CC51B03_0.PrivateFormalUnknownDiscriminants (Message);


   --
   -- Instances for formal derived tagged type with unknown discriminants:
   --

   package DerivedFormal_UndiscriminatedTaggedActual is new
     CC51B03_0.TaggedAncestorUnknownDiscriminants (FC51B00.Vector);

   package DerivedFormal_ClassWideActual is new
     CC51B03_0.TaggedAncestorUnknownDiscriminants (FC51B00.Vector'Class);

   package DerivedFormal_DiscriminatedTaggedActual is new
     CC51B03_0.TaggedAncestorUnknownDiscriminants (CC51B03_1.Extended_Vector);


begin
   Report.Test ("CC51B03", "Check that S'Definite returns true if the " &
                "actual corresponding to S is definite, and false otherwise");


   if not PrivateFormal_UndiscriminatedTaggedActual.Is_Definite then
      Report.Failed ("Formal private/unknown discriminants: wrong " &
                     "result for undiscriminated tagged actual");
   end if;  

   if PrivateFormal_ClassWideActual.Is_Definite then
      Report.Failed ("Formal private/unknown discriminants: wrong " &
                     "result for class-wide actual");
   end if;  

   if PrivateFormal_DiscriminatedTaggedActual.Is_Definite then
      Report.Failed ("Formal private/unknown discriminants: wrong " &
                     "result for discriminated tagged actual");
   end if;  

   if PrivateFormal_DiscriminatedUndefaultedRecordActual.Is_Definite then
      Report.Failed ("Formal private/unknown discriminants: wrong result " &
                     "for record actual with undefaulted discriminants");
   end if;  

   if not PrivateFormal_DiscriminatedDefaultedRecordActual.Is_Definite then
      Report.Failed ("Formal private/unknown discriminants: wrong result " &
                     "for record actual with defaulted discriminants");
   end if;  


   if not DerivedFormal_UndiscriminatedTaggedActual.Is_Definite then
      Report.Failed ("Formal derived/unknown discriminants: wrong result " &
                     "for undiscriminated tagged actual");
   end if;  

   if DerivedFormal_ClassWideActual.Is_Definite then
      Report.Failed ("Formal derived/unknown discriminants: wrong result " &
                     "for class-wide actual");
   end if;  

   if DerivedFormal_DiscriminatedTaggedActual.Is_Definite then
      Report.Failed ("Formal derived/unknown discriminants: wrong result " &
                     "for discriminated tagged actual");
   end if;  


   Report.Result;
end CC51B03;
