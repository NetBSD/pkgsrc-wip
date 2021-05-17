

     --==================================================================--


package body C460001_0 is

   procedure Target_Is_Level_0 (X : access Desig;
                                R : out Result_Kind) is
   begin
      -- The accessibility level of type Acc_L0 is 0.
      A0 := Acc_L0(X);
      R  := OK;
   exception
      when Program_Error =>    
         R := P_E;
      when others        =>    
         R := O_E;
   end Target_Is_Level_0;

   -----------------------------------------------
   procedure Never_Fails (X: access Desig;
                          R : out Result_Kind) is
      type Acc_Local is access all Desig;
      AL : Acc_Local;
   begin
      -- The type conversion below will always be safe, since the
      -- accessibility level (although not necessarily the static nesting
      -- depth) of Acc_Local will always be deeper than or the same as that 
      -- of the actual corresponding to X. 
      AL := Acc_Local(X);
      R  := OK;
   exception
      when Program_Error =>    
         R := P_E;
      when others        =>    
         R := O_E;
   end Never_Fails;

end C460001_0;
