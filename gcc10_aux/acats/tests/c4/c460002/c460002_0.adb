

     --==================================================================--


package body C460002_0 is

   procedure Target_Is_Level_0_Nest (Y: access Desig; S: out Result_Kind) is

      procedure Nested (X: access Desig; R: out Result_Kind) is
      -- This procedure attempts a type conversion on the access parameter to
      -- an access type declared at some nesting level.  Program_Error is
      -- raised if the accessibility level of the operand type is deeper than
      -- that of the target type.

      begin
         -- The accessibility level of type Acc_L0 is 0.
         A0 := Acc_L0(X);
         R  := OK;
      exception
         when Program_Error =>
            R := P_E;
         when others        =>
            R := O_E;
      end Nested;

   begin
      Nested (Y, S);
   end Target_Is_Level_0_Nest;

   -------------------------------------------------------------

   procedure Never_Fails_Nest (Y: access Desig; S: out Result_Kind) is

      type Acc_Deeper is access all Desig;
      AD : Acc_Deeper;

      function Nested (X: access Desig) return Result_Kind is
      begin
         -- The type conversion below will always be safe, since the
         -- accessibility level (although not necessarily the static nesting
         -- depth) of Acc_Deeper will always be deeper than or the same as that
         -- of the actual corresponding to Y.
         AD := Acc_Deeper(X);
         if Natural(Ident_Int(AD.C(1))) /= 3 then            --Avoid Optimization of AD
           Report.Failed ("Initial Values not correct.");
         end if;
         return OK;
      exception
         when Program_Error =>
            return P_E;
         when others        =>
            return O_E;
      end Nested;

   begin
      S := Nested (Y);
   end Never_Fails_Nest;

   -------------------------------------------------------------

   procedure Called_By_Never_Fails_Same
     (X: access Desig; R: out Result_Kind) is
      type Acc_Local is access all Desig;
      AL : Acc_Local;
   begin
      -- The type conversion below will always be safe, since the
      -- accessibility level (although not necessarily the static nesting
      -- depth) of Acc_Local will always be deeper than or the same as that
      -- of the actual corresponding to X.
      AL := Acc_Local(X);
      if Natural(Ident_Int(AL.C(1))) /= 3 then       --Avoid Optimization of AL
        Report.Failed ("Initial Values not correct.");
      end if;
      R  := OK;
   exception
      when Program_Error =>
         R := P_E;
      when others        =>
         R := O_E;
   end Called_By_Never_Fails_Same;

   -------------------------------------------------------------

   procedure Never_Fails_Same (Y: access Desig; S: out Result_Kind) is
   begin
      Called_By_Never_Fails_Same (Y, S);
   end Never_Fails_Same;

end C460002_0;
