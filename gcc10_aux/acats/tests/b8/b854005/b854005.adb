
with B854005A;
procedure B854005 is

   R1 : B854005A.Rec;

   function Ren_Count_1 return Natural renames R1.F1.F.Count;  -- ERROR: {4;1}

   function Ren_Count_2 return Natural renames R1.F2(1).Count; -- ERROR: {4;1}

   function Ren_Count_3 return Natural renames R1.F3.F.Count;  -- OK. {4;1}

   function Ren_Count_4 return Natural renames R1.F4.Count;    -- ERROR: {4;1}

   procedure Ren_Set_1 (Num : in Natural) renames R1.F1.F.Set; -- ERROR: {4;1}

   procedure Ren_Set_2 (Num : in Natural) renames R1.F2(1).Set;-- ERROR: {4;1}

   procedure Ren_Set_3 (Num : in Natural) renames R1.F3.F.Set; -- OK. {4;1}

   procedure Ren_Set_4 (Num : in Natural) renames R1.F4.Set;   -- ERROR: {4;1}

   procedure Ren_Bump_1 renames R1.F1.F.Bump;                  -- ERROR: {4;1}

   procedure Ren_Bump_2 renames R1.F2(1).Bump;                 -- ERROR: {4;1}

   procedure Ren_Bump_3 renames R1.F3.F.Bump;                  -- OK. {4;1}

   procedure Ren_Bump_4 renames R1.F4.Bump;                    -- ERROR: {4;1}

begin
   Ren_Bump_3;
   if Ren_Count_3 /= 4 then
       raise Program_Error with "wrong value (1)";
   end if;
   Ren_Set_3 (0);
   if Ren_Count_3 /= 0 then
       raise Program_Error with "wrong value (2)";
   end if;
end B854005;
