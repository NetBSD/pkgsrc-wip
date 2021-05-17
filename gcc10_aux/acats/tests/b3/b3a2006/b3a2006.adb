

     --==================================================================--


with B3A2006_0;
with B3A2006_1;

function B3A2006 (S : B3A2006_0.Integer_Set) return Natural is

   procedure Rename_L0 (J : Integer) renames B3A2006_1;          -- Level = 0.

   Result_L1 : Natural := 0;

   procedure Increment_L1 (I : Integer) is                       -- Level = 1.
   begin
      Result_L1 := Result_L1 + Natural(I);
   end Increment_L1;

   type Integer_Action_L1 is access procedure (I : Integer);     -- Level = 1.

   AP1 : Integer_Action_L1;


   procedure Iterate_L1 (S      : B3A2006_0.Integer_Set; 
                         Action : Integer_Action_L1) is
   begin
      null; -- Artificial for brevity.
   end Iterate_L1;

   --
   -- Nested task:
   --

   task Tsk;

   task body Tsk is

      Result_L2 : Natural := 0;

      procedure Rename_L1 (K : Integer)  renames Increment_L1;   -- Level = 1.
                          -- Renamed at deeper level than originally declared.

      procedure Increment_L2 (I : Integer) is                    -- Level = 2.
      begin
         Result_L2 := Result_L2 + Natural(I);
      end Increment_L2;

      type Integer_Action_L2 is access procedure (I : Integer);  -- Level = 2.

      AP2 : Integer_Action_L2;

      Renamed_AP1 : Integer_Action_L1 renames AP1;               -- Level = 1.
                          -- Renamed at deeper level than originally declared.

      type New_Int_Act_L1 is new Integer_Action_L1;              -- Level = 1.
                 -- Type declared at deeper level than ultimate ancestor type.
  
      NIA_L1 : New_Int_Act_L1;

   begin -- Tsk.

      B3A2006_0.Iterate_L0 (S, Increment_L2'Access);                -- ERROR:
                        -- Accessibility level of Increment_L2 is deeper than
                        -- that of B3A2006_0.Integer_Action_L0.

      Iterate_L1 (S, Increment_L2'Access);                          -- ERROR:
                        -- Accessibility level of Increment_L2 is deeper than
                        -- that of Integer_Action_L1.

      Iterate_L1 (S, Rename_L1'Access);                             -- OK.

      AP2 := B3A2006_1'Access;                                      -- OK.
      AP2 := Increment_L1'Access;                                   -- OK.
      AP2 := Increment_L2'Access;                                   -- OK.

      AP1 := B3A2006_1'Access;                                      -- OK.
      AP1 := Increment_L1'Access;                                   -- OK.
      AP1 := Increment_L2'Access;                                   -- ERROR:
                        -- Accessibility level of Increment_L2 is deeper than
                        -- that of Integer_Action_L1.

      Renamed_AP1 := Increment_L1'Access;                           -- OK.
      Renamed_AP1 := Increment_L2'Access;                           -- ERROR:
                        -- Accessibility level of Increment_L2 is deeper than
                        -- that of Integer_Action_L1.

      NIA_L1 := Increment_L1'Access;                                -- OK.
      NIA_L1 := Increment_L2'Access;                                -- ERROR:
                        -- Accessibility level of Increment_L2 is deeper than
                        -- that of New_Int_Act_L1.

   end Tsk;

begin -- B3A2006

   B3A2006_0.Iterate_L0 (S, B3A2006_1'Access);                      -- OK.
   B3A2006_0.Iterate_L0 (S, Increment_L1'Access);                   -- ERROR:
                        -- Accessibility level of Increment_L1 is deeper than
                        -- that of B3A2006_0.Integer_Action_L0.

   B3A2006_0.Iterate_L0 (S, Rename_L0'Access);                      -- OK.

   Iterate_L1 (S, B3A2006_1'Access);                                -- OK.
   Iterate_L1 (S, Increment_L1'Access);                             -- OK.

   return Result_L1;

end B3A2006;
