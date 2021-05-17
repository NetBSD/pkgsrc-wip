
with Report;

package body F611B00 is

   procedure TC_Clear is
   begin
     TC_Annotated_Event_Record_Count1_Called := False;
     TC_Annotated_Event_Record_Count2_Called := False;
     TC_Event_Record_Count1_Called           := False;
     TC_Event_Record_Count2_Called           := False;
     TC_Event_Record_Count1_Tag              := Ada.Tags.No_Tag;
     TC_Event_Record_Count2_Tag              := Ada.Tags.No_Tag;
   end TC_Clear;

   procedure TC_Log_Annotated_Event_Record_Count1_Called
             (Tag : Ada.Tags.Tag) is
   begin
      TC_Annotated_Event_Record_Count1_Called := True;
      TC_Event_Record_Count1_Tag              := Tag;
   end TC_Log_Annotated_Event_Record_Count1_Called;

   procedure TC_Log_Annotated_Event_Record_Count2_Called
             (Tag : Ada.Tags.Tag) is
   begin
      TC_Annotated_Event_Record_Count2_Called := True;
      TC_Event_Record_Count2_Tag              := Tag;
   end TC_Log_Annotated_Event_Record_Count2_Called;

   procedure TC_Log_Event_Record_Count1_Called (Tag : Ada.Tags.Tag) is
   begin
      TC_Event_Record_Count1_Called := True;
      TC_Event_Record_Count1_Tag    := Tag;
   end TC_Log_Event_Record_Count1_Called;

   procedure TC_Log_Event_Record_Count2_Called (Tag : Ada.Tags.Tag) is
   begin
      TC_Event_Record_Count2_Called := True;
      TC_Event_Record_Count2_Tag    := Tag;
   end TC_Log_Event_Record_Count2_Called;

   procedure TC_Output is
   begin
      Report.Comment
       ("Annotated_Event_Record_Count1_Called is " &
        Boolean'Image (TC_Annotated_Event_Record_Count1_Called));

      Report.Comment
       ("Annotated_Event_Record_Count2_Called is " &
        Boolean'Image (TC_Annotated_Event_Record_Count2_Called));

      Report.Comment
       ("Event_Record_Count1_Called is " &
        Boolean'Image (TC_Event_Record_Count1_Called));

      Report.Comment
       ("Event_Record_Count2_Called is " &
        Boolean'Image (TC_Event_Record_Count2_Called));

      Report.Comment ("");
   end TC_Output;

end F611B00;
