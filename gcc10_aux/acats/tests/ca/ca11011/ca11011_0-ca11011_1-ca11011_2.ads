
     --=================================================================--

-- The Subprogram that performs the actual file operations is contained in a
-- private package so that it is not accessible to any client.
-- Default parameters are used in most cases in the subprogram calls, since
-- the caller does not have visibility to these private types.

                                   -- Package OS.File_Manager.Internals
private package CA11011_0.CA11011_1.CA11011_2 is  

   Private_File_Counter : Integer renames File_Counter;         -- Grandparent
                                                                -- object.
   procedure Create 
     (Key         : in     File_Descriptor_Type; 
      File_Name   : in     File_Name_Type   := Get_File_Name;   -- Grandparent
                                                                -- prvt type,
                                                                -- prvt functn.
      File_Mode   : in     File_Mode_Type   := Init_Mode;       -- Grandparent
                                                                -- prvt type,
                                                                -- prvt const.
      File_Access : in     Permission_Type  := Init_Permission; -- Grandparent
                                                                -- prvt type,
                                                                -- prvt const.
      File_Status : in     File_Status_Type := Init_Status);    -- Grandparent
                                                                -- prvt type,
                                                                -- prvt const.

end CA11011_0.CA11011_1.CA11011_2;   -- Package OS.File_Manager.Internals
