
with F611B00;

package body C611B030.Child.Grandchild is

   function Count1 (Annotated_Event : in Annotated_Event_Record)
      return Integer is
   begin
      F611B00.TC_Log_Annotated_Event_Record_Count1_Called (
         Annotated_Event_Record'Class(Annotated_Event)'Tag);

      return Annotated_Event.No_Of_Occurrences;
   end Count1;

   function Count2 (Annotated_Event : in Annotated_Event_Record)
      return Integer is
   begin
      F611B00.TC_Log_Annotated_Event_Record_Count2_Called (
         Annotated_Event_Record'Class(Annotated_Event)'Tag);

      return Annotated_Event.No_Of_Occurrences;
   end Count2;

end C611B030.Child.Grandchild;
