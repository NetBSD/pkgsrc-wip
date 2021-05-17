
------------------------------------------------------------------- C392011

with Report;
with TCTouch;
with C392011_2.C392011_3;

procedure C392011 is

begin  -- Main test procedure.

  Report.Test ("C392011", "Check that if a function call with a " &
                          "controlling result is itself a controlling " &
                          "operand of an enclosing call on a dispatching " &
                          "operation, then its controlling tag value is " &
                          "determined by the controlling tag value of " &
                          "the enclosing call" );

  C392011_2.C392011_3.Build_List;
  TCTouch.Validate( "A" & "AC" & "ACE" & "AC" & "ACE", "Build List" );

  C392011_2.C392011_3.Traverse_List;
  TCTouch.Validate( "ACEFACEF" & 
                    "ACDACD" &  
                    "ACEFACEF" &  
                    "ACDACD" &  
                    "ABAB",
                    "Traverse List" );

  Report.Result;

end C392011;
