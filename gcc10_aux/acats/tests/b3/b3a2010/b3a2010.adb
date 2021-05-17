
     --==================================================================--


with B3A2010_0;
with B3A2010_1;
with B3A2010_2;

procedure B3A2010 is

   type Acc_L1 is access procedure (I : Integer);               -- Level = 1.

   --
   -- Cases where P'Access is in the visible part:
   --
   
   package Proc_Vis_A is new B3A2010_1 (B3A2010_0.Acc_L0);          -- ERROR:
                      -- Accessibility level of Proc_Vis_A.Designated_Proc_A
                      -- is deeper than that of B3A2010_0.Acc_L0.

   package Prov_Vis_B is new B3A2010_1 (Acc_L1);                      -- OK.

   --
   -- Cases where P'Access is in the private part:
   --   

   package Proc_Private_A is new B3A2010_2 (B3A2010_0.Acc_L0);      -- ERROR:
                      -- Accessibility level of Proc_Private_A.Designated_GB
                      -- is deeper than that of B3A2010_0.Acc_L0.

   package Proc_Private_B is new B3A2010_2 (Acc_L1);                  -- OK.

--
-- Nested subprogram:
--

   procedure Nested is

      type Acc_L2 is access procedure (I : Integer);            -- Level = 2.

      --
      -- Cases where P'Access is in the visible part:
      --

      package Proc_Vis_C is new B3A2010_1 (B3A2010_0.Acc_L0);        -- ERROR:
                       -- Accessibility level of Proc_Vis_C.Designated_Proc_A
                       -- is deeper than that of B3A2010_0.Acc_L0.

      package Proc_Vis_D is new B3A2010_1 (Acc_L1);                  -- ERROR:
                       -- Accessibility level of Proc_Vis_D.Designated_Proc_A
                       -- is deeper than that of Acc_L1.

      package Proc_Vis_E is new B3A2010_1 (Acc_L2);                    -- OK.

      --
      -- Cases where P'Access is in the private part:
      --   

      package Proc_Private_C is new B3A2010_2 (B3A2010_0.Acc_L0);   -- ERROR:
                       -- Accessibility level of Proc_Private_C.Designated_GB
                       -- is deeper than that of B3A2010_0.Acc_L0.

      package Proc_Private_D is new B3A2010_2 (Acc_L1);             -- ERROR:
                       -- Accessibility level of Proc_Private_C.Designated_GB
                       -- is deeper than that of Acc_L1.

      package Proc_Private_E is new B3A2010_2 (Acc_L2);                -- OK.


   begin -- Nested.
      null;
   end Nested;


begin -- B3A2010
   null;
end B3A2010;
