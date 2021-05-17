                                            -- visible.


     --==================================================================--


procedure CC70B01_0 (L : in out List_Type) is  -- Declarations in List_Mgr
begin                                          -- still directly visible.
   Reset (L);
   while not End_Of_List (L) loop
      Write_Element (L, Elem_Type'First);      -- This statement assumes
   end loop;                                   -- Elem_Type is discrete.
end CC70B01_0;
