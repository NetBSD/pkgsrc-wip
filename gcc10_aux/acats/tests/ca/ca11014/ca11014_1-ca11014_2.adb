
     --==================================================================--

package body CA11014_1.CA11014_2 is

   procedure Write_First_To_List (L : in out List_Mgr.List_Type) is
   begin
      List_Mgr.Reset (L);    -- Parent's formal package.

      while not List_Mgr.End_Of_List (L) loop     -- Parent's formal package.
         Write_Element (L, List_Mgr.Element_Type'First);   
                                                  -- Parent's operation, 
      end loop;                                   -- parent's formal.
      
   end Write_First_To_List;

end CA11014_1.CA11014_2;
