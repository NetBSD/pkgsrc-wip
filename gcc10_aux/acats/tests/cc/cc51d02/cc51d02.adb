

     --==================================================================--


with FC51D00;    -- Generic list abstraction.
with CC51D02_0;  -- Tagged type declarations.
with CC51D02_1;  -- Generic operation.

with Report;
procedure CC51D02 is

   use CC51D02_0;                                        -- All types & ops
                                                         -- directly visible.

   -- Begin test code declarations: -----------------------

   TC_Expected_1 : Blind_ID_Type'Class :=
                   Blind_ID_Type'(SSN => "111223333");
   TC_Expected_2 : Blind_ID_Type'Class :=
                   Named_ID_Type'("444556666", "Doe      ");


   TC_Initial_1  : Blind_ID_Type       := (SSN => "777889999");
   TC_Initial_2  : Named_ID_Type       := ("777889999", "Doe      ");
   TC_Initial_3  : Blind_ID_Type'Class := TC_Initial_2;

   -- End test code declarations. -------------------------


   package ID_Class_Lists is new FC51D00 (Blind_ID_Type'Class);

   procedure Update_and_Write is new CC51D02_1 (Blind_ID_Type'Class,
                                                ID_Class_Lists);

   Blind_List  : ID_Class_Lists.List_Type;
   Named_List  : ID_Class_Lists.List_Type;
   Maimed_List : ID_Class_Lists.List_Type;


begin
   Report.Test ("CC51D02", "Formal private extension, class-wide actual: " &
                "body of primitive subprogram executed is that of actual " &
                "type. Check for subprograms declared in formal package");


   Update_and_Write (Blind_List, TC_Initial_1);    -- Test root type actual.

   if (ID_Class_Lists.View_Element (1, Blind_List) not in Blind_ID_Type) then
      Report.Failed ("Result for root type actual is not in proper class");
   elsif (ID_Class_Lists.View_Element (1, Blind_List) /= TC_Expected_1) then
      Report.Failed ("Wrong result for root type actual");
   end if;


   Update_and_Write (Named_List, TC_Initial_2);    -- Test derived type actual.

   if (ID_Class_Lists.View_Element (1, Named_List) not in Named_ID_Type) then
      Report.Failed ("Result for derived type actual is not in proper class");
   elsif (ID_Class_Lists.View_Element (1, Named_List)/= TC_Expected_2) then
      Report.Failed ("Wrong result for derived type actual");
   end if;


   -- In the subtest below, an object of a class-wide type (TC_Initial_3) is
   -- passed to Update_and_Write. It has been initialized with an object of
   -- type Named_ID_Type, so the result should be identical to
   -- that of the Named_ID_Type subtest (namely TC_Expected_2). Note that
   -- a new list of Named IDs is used (Maimed_List). This is to assure test
   -- validity, since Named_List has already been updated by a previous
   -- subtest.

   Update_and_Write (Maimed_List, TC_Initial_3);   -- Test class-wide actual.

   if (ID_Class_Lists.View_Element (1, Maimed_List) not in Named_ID_Type) then
      Report.Failed ("Result for class-wide actual is not in proper class");
   elsif (ID_Class_Lists.View_Element (1, Maimed_List) /= TC_Expected_2) then
      Report.Failed ("Wrong result for class-wide actual");
   end if;


   Report.Result;
end CC51D02;
