
     --==================================================================--

with Report;
with CD40001_0;

procedure CD40001 is

begin  -- Main test procedure.

  Report.Test ("CD40001", "Check that Enumeration_Representation_Clauses " &
                          "are supported for codes in the range " &
                          "System.Min_Int..System.Max_Int" );
   
  CD40001_0.TC_Check_Press;

  CD40001_0.TC_Check_Add;

  CD40001_0.TC_Check_Minus;

  Report.Result;

end CD40001;
