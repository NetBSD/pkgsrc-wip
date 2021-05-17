

     --==================================================================--


with CC51001_0;  -- Root type for message class.
with CC51001_1;  -- Extensions to message class.
with CC51001_2;  -- I/O operations for message class.

with Report;
procedure CC51001 is

   -- Instantiate for various types in the class:

   package Msgs   is new CC51001_2 (CC51001_0.Msg_Type);         -- Definite.
   package FMsgs  is new CC51001_2 (CC51001_1.From_Msg_Type);    -- Indefinite.
   package TFMsgs is new CC51001_2 (CC51001_1.To_From_Msg_Type); -- Indefinite.



   Msg   : CC51001_0.Msg_Type         := (Text => "This is message #001");
   FMsg  : CC51001_1.From_Msg_Type    := (Text => "This is message #002",
                                          SLen => 2,
                                          From => "Me");
   TFMsg : CC51001_1.To_From_Msg_Type := (Text => "This is message #003",
                                          From => "You       ",
                                          DLen => 4,
                                          To   => "Them");

   Expected_Msg   : constant String := "This is message #001";
   Expected_FMsg  : constant String := "This is message #002";
   Expected_TFMsg : constant String := "This is message #003";

begin
   Report.Test ("CC51001", "Check that the formal derived type may have " &
                "an unknown discriminant part. Check that the ancestor " &
                "type in a formal derived type definition may be a " &
                "tagged type, and that the actual parameter may be any " &
                "definite or indefinite descendant of the ancestor type");

   if (Msgs.Print_Message (Msg) /= Expected_Msg) then
      Report.Failed ("Wrong result for definite root type");
   end if;

   if (FMsgs.Print_Message (FMsg) /= Expected_FMsg) then
      Report.Failed ("Wrong result for direct indefinite derivative");
   end if;

   if (TFMsgs.Print_Message (TFMsg) /= Expected_TFMsg) then
      Report.Failed ("Wrong result for Indirect indefinite derivative");
   end if;

   Report.Result;
end CC51001;
