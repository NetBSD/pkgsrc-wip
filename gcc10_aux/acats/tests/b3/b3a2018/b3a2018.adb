
with B3A2018A; use B3A2018A;
procedure B3A2018 is

   type AC_Int is access constant Int;

   P1 : AC_Int;

   P2 : P_AC_Int;

   VA1 : aliased Int := 53;

   function Func_1 (Value : aliased in Int) return Int is
      -- Case from AI05-0235-1.
   begin
      P1 := Value'Access;                                 -- ERROR: {7;1}
      return 12;
   end Func_1;

   function Func_2 (Value : aliased in Int) return AC_Int is
      -- Case from AI12-0277-1.
   begin
      return Value'Access;                                -- ERROR: {7;1}
   end Func_2;

   function Func_3 (Value : aliased in Int) return access constant Int is
      -- The special case of this rule.
   begin
      return Value'Access;                                -- OK. {7;1}
   end Func_3;

   -- Library-level versions: (these should be illegal even in a correct
   -- Ada 2005 implementation, since the level of Value was that of the
   -- declaration of the body)

   function Func_4 (Value : aliased in Int) return Int is
   begin
      P2 := Value'Access;                                 -- ERROR: {7;1}
      return 4;
   end Func_4;

   function Func_5 (Value : aliased in Int) return P_AC_Int is
   begin
      return Value'Access;                                -- ERROR: {7;1}
   end Func_5;

   function Func_6 (Value : aliased in Int) return P_AC_Int is
      -- The existence of an explicitly aliased parameter doesn't
      -- change the rules for a return statement.
   begin
      VA1 := Value;
      return VA1'Access;                                  -- ERROR: {7;1}
   end Func_6;

   function Outer_1 (Num : in Natural) return AC_Int is
      A_Value : aliased Int := 12;
   begin
      case Num is
         when 1 =>
            return new Int'(Func_1 (A_Value));            -- ERROR: {13;1}
               -- Here, the "master of the call" is determined by
               -- 3.10.2(10.2/3) to be the master of AC_Int; that
               -- causes the parameter Value to violate 6.4.1(6.4/3).
         when 2 =>
            return Func_2 (A_Value);                      -- OK. {13;1}
               -- A_Value here would fail the dynamic check of 6.4.1(15.1/3)
               -- and raise Program_Error; 3.10.2(10.5/3) applies; the
               -- outer caller would use 3.10.2(10.6/3) [it's an assignment
               -- not an initialization] so the master is that of the main
               -- subprogram; but there's no static failure (the level isn't
               -- known statically). Ain't accessibility fun?? ;-)
         when 3 =>
            return AC_Int (Func_3 (A_Value));             -- ERROR: {13;1}
               -- Here, the "master of the call" is determined by
               -- 3.10.2(10.3/3) to be the master of AC_Int; that
               -- causes the parameter Value to violate 6.4.1(6.4/3).
         when 4 =>
            return AC_Int (Func_3 (VA1));                 -- OK. {13;1}
               -- As above, the "master of the call" is determined
               -- to be the master of AC_Int; VA1 matches that.
         when 5 =>
            declare
               LP : access constant Int := Func_3 (A_Value); -- ERROR: {16;1}
               -- Here, the "master of the call" is determined by
               -- 3.10.2(10.2/3) to be the master of LP; that
               -- causes the parameter Value to violate 6.4.1(6.4/3).
            begin
               return AC_Int (LP);                        -- OK. {16;1}
               -- LP doesn't have a static level by 3.10.2(19.1/3), so
               -- no static check here. This will fail a dynamic check.
            end;
         when 6 =>
            P1 := Func_2 (A_Value);                       -- OK. {13;1}
               -- Here, the "master of the call" is determined by
               -- 3.10.2(10.6/3) to be the master of this assignment
               -- (careful: this is not an initialization!),
               -- A_Value lives longer than that.
            return P1;                                    -- OK. {13;1}
         when others =>
            raise Program_Error;
      end case;
   end Outer_1;

   function Outer_2 (Num : in Natural) return P_AC_Int is
      A_Value : aliased Int := 12;
   begin
      case Num is
         when 1 =>
            return new Int'(Func_4 (A_Value));            -- ERROR: {13;1}
               -- See limb 1 in Outer_1 using P_AC_Int rather than AC_Int.
         when 2 =>
            return Func_5 (A_Value);                      -- OK. {13;1}
               -- See limb 2 in Outer_1 using P_AC_Int rather than AC_Int.
         when 3 =>
            return P_AC_Int (Func_3 (A_Value));           -- ERROR: {13;1}
               -- See limb 3 in Outer_1 using P_AC_Int rather than AC_Int.
         when 4 =>
            return new Int'(Func_4 (VA1));                -- ERROR: {13;1}
               -- See limb 1 in Outer_1 using P_AC_Int rather than AC_Int.
         when 5 =>
            return Func_5 (VA1);                          -- OK. {13;1}
               -- See limb 2 in Outer_1 using P_AC_Int rather than AC_Int.
         when 6 =>
            return Func_6 (VA1);                          -- OK. {13;1}
               -- See limb 2 in Outer_1 using P_AC_Int rather than AC_Int.
         when 7 =>
            return P_AC_Int (Func_3 (VA1));               -- ERROR: {13;1}
               -- See limb 3 in Outer_1 using P_AC_Int rather than AC_Int.
         when 8 =>
            return P_AC_Int (Func_3 (PVA1));              -- OK. {13;1}
               -- See limb 4 in Outer_1 using P_AC_Int rather than AC_Int.
         when 9 =>
            declare
               LP : access constant Int := Func_3 (VA1);  -- ERROR: {16;1}
               -- See limb 5 in Outer_1 using VA1 rather than A_Value.
            begin
               return P_AC_Int (LP);                      -- OK. {16;1}
               -- See limb 5 in Outer_1 using P_AC_Int rather than AC_Int.
            end;
         when 10 =>
            P2 := Func_5 (VA1);                           -- OK. {13;1}
               -- See limb 6 in Outer_1 using VA1 rather than A_Value.
            return P2;                                    -- OK. {13;1}
         when others =>
            raise Program_Error;
      end case;
   end Outer_2;

begin

   for I in 1 .. 6 loop
      P1 := Outer_1 (I);
   end loop;

   for I in 1 .. 10 loop
      P2 := Outer_2 (I);
   end loop;

end B3A2018;

