
     --=================================================================--

-- Subprogram that performs the actual file operation is contained in a
-- private package so that it is not accessible to any client, and can be
-- modified/extended without requiring recompilation of the clients of the
-- parent (since this package is "withed" by the parent body only.)


                               -- Grandchild Package OS.File_Manager.Internals
private package CA11009_0.CA11009_1.CA11009_2 is  

   Initial_Permission : constant Permission_Type  := User;  -- Grandparent
   Initial_Status     : constant File_Status_Type := Open;  -- literals.
   Initial_Filename   : constant File_Name_Type   :=  -- Grandparent type.
     Get_File_Name;                                   -- Grandparent function.

   function Create (Mode : File_Mode_Type)                      
     return File_Descriptor_Type;                     -- Grandparent type.

end CA11009_0.CA11009_1.CA11009_2;   
