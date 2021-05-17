

     --==================================================================--


with CC70001_0.CC70001_1;  -- Generic list abstraction + additional operations.
generic

   -- Import the list abstraction defined in CC70001_0, as well as the
   -- additional operations defined in CC70001_0.CC70001_1. Declare a formal
   -- discrete type. Restrict this generic procedure to operate only on lists
   -- of discrete elements by passing the formal discrete type as an actual
   -- parameter to the formal (parent) package.

   type Elem_Type is (<>);                  -- Discrete types only.
   with package List_Mgr is new CC70001_0 (Elem_Type);
   with package List_Ops is new List_Mgr.CC70001_1 (<>);

procedure CC70001_2 (L : in out List_Mgr.List_Type);
