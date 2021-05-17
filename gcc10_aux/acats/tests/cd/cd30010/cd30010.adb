
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

-- there is no package body CD30010_0

------------------------------------------------------------------- CD30010

with Report;
with TCTouch;
with System.Storage_Elements;
with CD30010_0;
procedure CD30010 is

   use type System.Storage_Elements.Storage_Offset;

   A_Word   : CD30010_0.Word_Stuff(0..15);

   A_Double : CD30010_0.Double_Stuff(0..15);

   procedure Unexpected( Message : String; Wanted, Got: Integer ) is
   begin
      Report.Failed (Message & " Wanted:" &
                     Wanted'Image & " Got:" & Got'Image);
   end Unexpected;

begin  -- Main test procedure.

   Report.Test ("CD30010", "Check that Component_Sizes that are specified "
                        & "with an aspect specification and that are "
                        & "multiples of the word size are supported. Check "
                        & "that for such Component_Sizes arrays contain no "
                        & "gaps between components");

   if A_Word'Size /= CD30010_0.Word_Stuff'Component_Size * 16 then
      Unexpected ("Word Size",
                   CD30010_0.Word_Stuff'Component_Size * 16,
                   A_Word'Size);
   end if;

   if A_Double'Size /= CD30010_0.Double_Stuff'Component_Size * 16 then
      Unexpected ("Double word Size",
                  CD30010_0.Double_Stuff'Component_Size * 16,
                  A_Double'Size);
   end if;

   Report.Result;

end CD30010;
