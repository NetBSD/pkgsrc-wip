

     --==================================================================--


package body C3A2003_0 is

   procedure Target_Is_Level_0_Nest (Y: access Desig; S: out Result_Kind) is


      -- This procedure utilizes 'Access on a dereference of an access
      -- parameter, and assigned to an access object whose type A is
      -- declared at some nesting level.  Program_Error is raised if
      -- the accessibility level of the operand type is deeper than that
      -- of the target type.

      procedure Nested (X: access Desig; R: out Result_Kind) is
         -- Dereference of an access_to_object value is aliased.
         Ren : Desig renames X.all;                -- Renaming of a dereference
      begin                                        -- of an access parameter.
         -- The accessibility level of type A0 is 0.
         A0 := Ren'Access;
         R  := OK;
      exception
         when Program_Error =>
            R := P_E;
         when others        =>
            R := O_E;
      end Nested;

   begin   -- Target_Is_Level_0_Nest
      Nested (Y, S);
   end Target_Is_Level_0_Nest;

   ------------------------------------------------------------------

   procedure Never_Fails_Nest (Y: access Desig; S: out Result_Kind) is

      type Acc_Deeper is access all Desig;
      AD : Acc_Deeper;

      function Nested (X: access Desig) return Result_Kind is
      begin
         -- X.all'Access below will always be safe, since the accessibility
         -- level (although not necessarily the static nesting depth) of the
         -- type of AD will always be deeper than or the same as that of the
         -- actual corresponding to Y.
         AD := X.all'Access;
         if Ident_Int (AD(4)) /= 3 then            --Avoid Optimization of AD
           FAILED ("Initial Values not correct.");
         end if;
         return OK;
      exception
         when Program_Error =>
            return P_E;
         when others        =>
            return O_E;
      end Nested;

   begin  -- Never_Fails_Nest
      S := Nested (Y);
   end Never_Fails_Nest;

   ------------------------------------------------------------------

   procedure Called_By_Never_Fails_Same
     (X: access Desig; R: out Result_Kind) is
      type Acc_Local is access all Desig;
      AL : Acc_Local;

      -- Dereference of an access_to_object value is aliased.
      Ren : Desig renames X.all;                   -- Renaming of a dereference
   begin                                           -- of an access parameter.
      -- Ren'Access below will always be safe, since the accessibility
      -- level (although not necessarily the static nesting depth) of
      -- type of AL will always be deeper than or the same as that of the
      -- actual corresponding to Y.
      AL := Ren'Access;
      if Ident_Int (AL(4)) /= 3 then       --Avoid Optimization of AL
        FAILED ("Initial Values not correct.");
      end if;
      R  := OK;
   exception
      when Program_Error =>
         R := P_E;
      when others        =>
         R := O_E;
   end Called_By_Never_Fails_Same;

   ------------------------------------------------------------------

   procedure Never_Fails_Same (Y: access Desig; S: out Result_Kind) is
   begin
      Called_By_Never_Fails_Same (Y, S);
   end Never_Fails_Same;

end C3A2003_0;
