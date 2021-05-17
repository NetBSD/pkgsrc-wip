
-- No body for BC51006_2.


     --==================================================================--


with BC51006_0;  -- Type definitions.
with BC51006_1;  -- Array formal types.
with BC51006_2;  -- Tagged formal types.
procedure BC51006 is

--
-- Array Types :
--

   package Array_Unconstrained_Subtype is new
     BC51006_1 (BC51006_0.My_Messages);                               -- OK.


   package Array_Ancestor is new
     BC51006_1 (BC51006_0.Message_Table);                             -- OK.


   package Array_Constrained_Subtype is new
     BC51006_1 (BC51006_0.Six_Messages);                              -- ERROR:
                                                         -- Actual constrained.

   package Array_Constrained_Derived is new
     BC51006_1 (BC51006_0.Ten_Messages);                              -- ERROR:
                                                         -- Actual constrained.


--
-- Tagged Types :
--

   package Tagged_Unconstrained_Derived is new
     BC51006_2 (BC51006_0.New_Node);                                  -- OK.

   package Tagged_Ancestor is new
     BC51006_2 (BC51006_0.Node);                                      -- OK.

   package Tagged_Constrained_Subtype is new
     BC51006_2 (BC51006_0.Len15_Node);                                -- ERROR:
                                                         -- Actual constrained.

   package Tagged_Constrained_Derived is new
     BC51006_2 (BC51006_0.List_Node);                                 -- ERROR:
                                                         -- Actual constrained.

begin
   null;
end BC51006;
