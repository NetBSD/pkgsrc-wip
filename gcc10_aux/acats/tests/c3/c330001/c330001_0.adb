
     --==================================================================--

package body C330001_0 is  

   function Indef_Func_1 return FullViewDefinite_Unknown_Disc is
      Var_1 : FullViewDefinite_Unknown_Disc;      -- No need for explicit 
                                                  -- constraints, use initial
   begin                                          -- values.
      return Var_1;
   end Indef_Func_1;

   ------------------------------------------------------------------
   function Indef_Func_2 (P : Sub_Type) return Indefinite_W_Inherit_Disc_2 is
      Var_2 : Indefinite_W_Inherit_Disc_2 := (D => 5, C1 => "Hello", S => P);
   begin
      return Var_2;
   end Indef_Func_2;

end C330001_0;
