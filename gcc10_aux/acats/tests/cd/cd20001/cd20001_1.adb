
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body CD20001_1 is

   function Next_Factor ( Value : Positive ) return Integer is
   -- Returns the factor of Word_Size that is next larger than Value.
   -- If Value is greater than Word_Size, then returns Word_Size.
     Test   : Integer := Value;
     Found  : Boolean := False;
  begin  -- Next_Factor
     while not Found and Test <= System.Word_Size loop
       if System.Word_Size mod Test = 0 then
          Found := True;
       else
          Test := Test + 1;
       end if;
     end loop;
     if Found then
        return Test;
     else
        return System.Word_Size;
     end if;
  end Next_Factor;

  procedure TC_Check_Values is
  begin
  
    if Pact_Aray_2'Component_Size > Next_Factor ( Bits_2'Size ) then
       Report.Failed
          ( "2 bit element Packed Array'Component_Size too big" );
    end if;

    TCTouch.Assert( Pact_Aray_2'Component_Size <= Pact_Aray_2'Size,
                    "2 bit Component_Size greater than array size" );

    if Pact_Aray_3'Component_Size > Next_Factor ( Bits_3'Size ) then
       Report.Failed
          ( "3 bit element Packed Array'Component_Size too big" );
    end if;

    TCTouch.Assert( Pact_Aray_3'Component_Size <= Pact_Aray_3'Size,
                    "3 bit Component_Size greater than array size" );

    if Pact_Aray_7'Component_Size > Next_Factor ( Bits_7'Size ) then
       Report.Failed
          ( "7 bit element Packed Array'Component_Size too big" );
    end if;

    TCTouch.Assert( Pact_Aray_7'Component_Size <= Pact_Aray_7'Size,
                    "7 bit Component_Size greater than array size" );

    if Pact_Aray_8'Component_Size > Next_Factor ( Bits_8'Size ) then
       Report.Failed
          ( "8 bit element Packed Array'Component_Size too big" );
    end if;

    TCTouch.Assert( Pact_Aray_8'Component_Size <= Pact_Aray_8'Size,
                    "8 bit Component_Size greater than array size" );

    if System.Word_Size > 8 then

      if Pact_Aray_9'Component_Size > Next_Factor ( Bits_9'Size ) then
         Report.Failed
            ( "9 bit element Packed Array'Component_Size too big" );
      end if;

      TCTouch.Assert( Pact_Aray_9'Component_Size <= Pact_Aray_9'Size,
                    "9 bit Component_Size greater than array size" );

      if Pact_Aray_15'Component_Size > Next_Factor ( Bits_15'Size ) then
         Report.Failed
            ( "15 bit element Packed Array'Component_Size too big" );
      end if;

      TCTouch.Assert( Pact_Aray_15'Component_Size <= Pact_Aray_15'Size,
                    "15 bit Component_Size greater than array size" );

    end if;

  end TC_Check_Values;

end CD20001_1;
