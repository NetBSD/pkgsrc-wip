

     --==================================================================--


package body C392D03_0 is

   procedure Focus (C     : in out Auto_Focus;
                    Depth : in     F392D00.Depth_Of_Field) is
   begin
      -- Artificial for testing purposes.
      C.DOF := 52;
   end Focus;

   -----------------------------------------------------------
   procedure Focus (C     : in out Auto_Flashing;
                    Depth : in     F392D00.Depth_Of_Field) is
   begin
      -- Artificial for testing purposes.
      C.DOF := 91;
   end Focus;

end C392D03_0;
