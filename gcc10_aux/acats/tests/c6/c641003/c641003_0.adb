

package body C641003_0 is

   pragma Assertion_Policy (Check);

   procedure Get_Info (Usable    : out Boolean;
                       Kind      : out Typical_Status;
                       Count     : out Small_Even;
                       Flags     : out Valid_Flags;
                       Data      : out Float_Natural;
                       Magnitude : out Smaller_Fixed;
                       Test_Case : in Cases) is
      -- Returns a different result for each test case. (See spec for
      -- details).
   begin
      -- Note: We cannot read any of the out parameters lest they be
      -- invalid for the declared subtype.
      case Test_Case is
         when 'A' =>
            Usable := True;
            Kind   := Raw;
            Flags  := 16#0010#;
         when 'B' =>
            Usable := True;
            Kind   := Solved;
            Count  := 12;
            Flags  := 16#0012#;
            Data   := 1.75;
            Magnitude := 0.625;
         when 'C' =>
            Usable := False;
         when 'D' =>
            Usable := True;
            Kind   := Folded;
            Flags  := 16#000C#;
            Count  := 4;
         when 'E' =>
            Usable := True;
            Kind   := Solved;
            Count  := 16;
            Flags  := 16#0028#;
            Data   := 1.25;
            Magnitude := -0.25;
         when 'F' =>
            Usable := True;
            Kind   := Bound;
            Flags  := 16#008A#;
            Count  := 6;
      end case;
   end Get_Info;
       
end C641003_0;
