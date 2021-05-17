

     --==================================================================--


procedure CC70001_2 (L : in out List_Mgr.List_Type) is
begin
   List_Mgr.Reset (L);
   while not List_Mgr.End_Of_List (L) loop
      List_Ops.Write_Element (L, Elem_Type'First);
   end loop;
end CC70001_2;
