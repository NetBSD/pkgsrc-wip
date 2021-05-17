

     --==================================================================--


--                           --
-- Formal package used here. --
--                           --

with FC51D00;    -- Generic list abstraction.
with CC51D02_0;  -- Tagged type declarations.
generic          -- This procedure simulates a generic operation for types
                 -- in the class rooted at Blind_ID_Type.
   type Elem_Type (<>) is new CC51D02_0.Blind_ID_Type with private;
   with package List_Mgr is new FC51D00 (Elem_Type);
procedure CC51D02_1 (L : in out List_Mgr.List_Type; E : in Elem_Type);
