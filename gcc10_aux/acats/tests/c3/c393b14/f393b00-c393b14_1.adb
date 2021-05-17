 -- Alert_Foundation.Public_Child

--=======================================================================--

with F393B00.C393B14_0;               -- private sibling is visible in the
  -- Alert_Foundation.Private_Child   -- body of a public sibling
package body F393B00.C393B14_1 is
     -- Alert_Foundation.Public_Child
  package Priv renames F393B00.C393B14_0;

  procedure Init is
    begin
      Priv.PA.Private_Field     := 5;
      Priv.PA.New_Private_Field := 10;
    end Init;

  procedure Modify is
    begin 
      Priv.Handle (Priv.PA);
    end Modify;

  function Check_Before return Boolean is
    begin
      return ((Priv.PA.Private_Field = 5) 
               and (Priv.PA.New_Private_Field =10));
    end Check_Before;

  function Check_After return Boolean is
    begin
      return ((Priv.PA.Private_Field = 1)
               and (Priv.PA.New_Private_Field = 2));
    end Check_After;

end F393B00.C393B14_1;
