

     --==================================================================--


with C460004_0;
use  C460004_0;

with Report;
procedure C460004 is

   Tag_Type_Init    :  constant Tag_Type   := (C1 => 0);
   DTag_Type_Init   :  constant DTag_Type  := (Tag_Type_Init with "Hello");
   DDTag_Type_Init  :  constant DDTag_Type := (DTag_Type_Init with "World");

   Tag_Type_Value   :  constant Tag_Type   := (C1 => 25);
   DTag_Type_Value  :  constant DTag_Type  := (Tag_Type_Value  with "Earth");
   DDTag_Type_Value :  constant DDTag_Type := (DTag_Type_Value with "Orbit");

begin

   Report.Test ("C460004", "Check that for a view conversion of a "      &
                "class-wide operand, Constraint_Error is raised if the " &
                "tag of the operand does not identify a specific type "  &
                "covered by or descended from the target type");

--
-- View conversion to specific type:
--

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
         Target : Tag_Type := Tag_Type_Init;     
      begin
         Target := Tag_Type(P);                      
         if (Target /= Tag_Type_Value) then
            Report.Failed ("Target has wrong value: #01");
         end if;
      exception
         when Constraint_Error => 
            Report.Failed ("Constraint_Error raised: #01");
         when others           => 
            Report.Failed ("Unexpected exception: #01");
      end CW_Proc;

   begin
      CW_Proc (DDTag_Type_Value);
   end;

   ----------------------------------------------------------------------

   declare
      Target : DTag_Type := DTag_Type_Init;           
   begin
      Target := DTag_Type(CWFunc(DDTag_Type_Value));  
      if (Target /= DTag_Type_Value) then
         Report.Failed ("Target has wrong value: #02");
      end if;
   exception
      when Constraint_Error => Report.Failed ("Constraint_Error raised: #02");
      when others           => Report.Failed ("Unexpected exception: #02");
   end;

   ----------------------------------------------------------------------

   declare
      Target : DDTag_Type;
   begin
      Target := DDTag_Type(CWFunc(Tag_Type_Value));
                -- CWFunc returns a Tag_Type; its tag is preserved through 
                -- the view conversion.  Constraint_Error should be raised.

      Report.Failed ("Constraint_Error not raised: #03"); 

   exception
      when Constraint_Error => null;                 -- expected exception
      when others           => Report.Failed ("Unexpected exception: #03");
   end;

   ----------------------------------------------------------------------

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
      begin
         NewProc (DDTag_Type(P));
         Report.Failed ("Constraint_Error not raised: #04"); 
                                                         
      exception
         when Constraint_Error => null;              -- expected exception
         when others           => Report.Failed ("Unexpected exception: #04");
      end CW_Proc;
 
   begin
      CW_Proc (DTag_Type_Value);
   end;

   ----------------------------------------------------------------------

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
         Target : DDTag_Type := DDTag_Type_Init; 
      begin
         Target := DDTag_Type(P);
         if (Target /= DDTag_Type_Value) then
            Report.Failed ("Target has wrong value: #05");
         end if;

      exception
         when Constraint_Error => 
            Report.Failed ("Constraint_Error raised: #05");
         when others           
            => Report.Failed ("Unexpected exception: #05");
      end CW_Proc;
 
   begin
      CW_Proc (DDTag_Type_Value);
   end;


--
-- View conversion to class-wide type:
--

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
         Operand : Tag_Type'Class := P;
      begin
         Proc( DTag_Type'Class(Operand) );
         Report.Failed ("Constraint_Error not raised: #06");

      exception
         when Constraint_Error => null;              -- expected exception
         when others           => Report.Failed ("Unexpected exception: #06");
      end CW_Proc;
 
   begin
      CW_Proc (Tag_Type_Init);
   end;

   ----------------------------------------------------------------------

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
         Operand : Tag_Type'Class := P;
      begin
         Proc( DDTag_Type'Class(Operand) );
         Report.Failed ("Constraint_Error not raised: #07");

      exception
         when Constraint_Error => null;              -- expected exception
         when others           => Report.Failed ("Unexpected exception: #07");
      end CW_Proc;
 
   begin
      CW_Proc (Tag_Type_Init);
   end;

   ----------------------------------------------------------------------

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
         Operand : Tag_Type'Class := P;
      begin
         Proc( DTag_Type'Class(Operand) );  
         if Operand not in DTag_Type then
            Report.Failed ("Operand has wrong tag: #08");
         elsif (Operand /= Tag_Type'Class (DTag_Type_Value)) then
            Report.Failed ("Operand has wrong value: #08");
         end if;

      exception
         when Constraint_Error => 
            Report.Failed ("Constraint_Error raised: #08");
         when others           => 
            Report.Failed ("Unexpected exception: #08");
      end CW_Proc;
 
   begin
      CW_Proc (DTag_Type_Init);
   end;

   ----------------------------------------------------------------------

   declare
      procedure CW_Proc (P : Tag_Type'Class) is
         Operand : Tag_Type'Class := P;
      begin
         Proc( Tag_Type'Class(Operand) );
         if Operand not in DDTag_Type then
            Report.Failed ("Operand has wrong tag: #09");
         elsif (Operand /= Tag_Type'Class (DDTag_Type_Value)) then
            Report.Failed ("Operand has wrong value: #09");
         end if;

      exception
         when Constraint_Error => 
            Report.Failed ("Constraint_Error raised: #09");
         when others           => 
            Report.Failed ("Unexpected exception: #09");
      end CW_Proc;
 
   begin
      CW_Proc (DDTag_Type_Init);
   end;


   Report.Result;

end C460004;
