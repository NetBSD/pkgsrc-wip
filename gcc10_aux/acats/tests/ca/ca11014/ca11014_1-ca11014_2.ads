
     --==================================================================--

-- Generic child of list operation.  This child adds a layer of 
-- functionality to the parent generic.

generic

package CA11014_1.CA11014_2 is

   procedure Write_First_To_List (L : in out List_Mgr.List_Type);

   -- ... Various other operations used by the application.

end CA11014_1.CA11014_2;
