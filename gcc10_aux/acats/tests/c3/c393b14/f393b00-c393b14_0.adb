 -- Alert_Foundation.Private_Child

--=======================================================================--

package body F393B00.C393B14_0 is
                  -- Alert_Foundation.Private_Child

  procedure Handle (PA : in out Implementation_Specific_Alert_Type) is
    begin
      PA.Private_Field := 1;
      PA.New_Private_Field := PA.Private_Field + 1;
    end;

end F393B00.C393B14_0;
