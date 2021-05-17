

     --==================================================================--

package body C3A2002_0 is

   procedure A_Is_Level_0 (X : access Desig;
                           R : out Result_Kind) is
   begin
      -- The accessibility level of the type of A0 is 0.
      A0 := X.all'Access;
      R  := OK;
   exception
      when Program_Error =>    
         R := P_E;
      when others        =>    
         R := O_E;
   end A_Is_Level_0;

   -----------------------------------------------
   procedure Never_Fails (X: access Desig;
                          R : out Result_Kind) is
      type Acc_Local is access all Desig;
      AL : Acc_Local;
   begin
      -- X.all'Access below will always be safe, since the accessibility
      -- level (although not necessarily the static nesting depth) of the
      -- type of AL will always be deeper than or the same as that of the 
      -- actual corresponding to Y. 
      AL := X.all'Access;
      R  := OK;
   exception
      when Program_Error =>    
         R := P_E;
      when others        =>    
         R := O_E;
   end Never_Fails;

end C3A2002_0;
