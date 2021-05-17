
------------------------------------------------------------------- CD20001

with Report;
with CD20001_0;
with CD20001_1;

procedure CD20001 is

begin  -- Main test procedure.

  Report.Test ("CD20001", "Check that packed records are packed as tightly " &
                          "as possible.  Check that Boolean objects are " &
                          "packed one to a bit. " &
                          "Check that the Component_Size for a packed " &
                          "array type is the value which is less than or " &
                          "equal to the Size of the component type, " &
                          "rounded up to the nearest factor of word_size" );
   
  CD20001_0.TC_Check_Values;

  CD20001_1.TC_Check_Values;

  Report.Result;

end CD20001;
