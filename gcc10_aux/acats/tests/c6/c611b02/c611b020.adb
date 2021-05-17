
with F611B00;

package body C611B020 is

   procedure Event_Occurred (Event : in out Event_Record) is
   begin
      Event.No_Of_Occurrences := Event.No_Of_Occurrences + 1;
   end Event_Occurred;

   function Count1 (Event : in Event_Record) return Integer is
   begin
      F611B00.TC_Log_Event_Record_Count1_Called (
         Event_Record'Class(Event)'Tag);

      return Event.No_Of_Occurrences;
   end Count1;

   function Count2 (Event : in Event_Record) return Integer is
   begin
      F611B00.TC_Log_Event_Record_Count2_Called (
         Event_Record'Class(Event)'Tag);

      return Event.No_Of_Occurrences;
   end Count2;

end C611B020;
