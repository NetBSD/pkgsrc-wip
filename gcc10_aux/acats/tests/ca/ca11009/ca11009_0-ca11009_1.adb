                          -- Grandchild Package body OS.File_Manager.Internals

     --=================================================================--

                                     -- "With" of a child package 
                                     -- by the parent body.
with CA11009_0.CA11009_1.CA11009_2;  -- Grandchild OS.File_Manager.Internals

package body CA11009_0.CA11009_1 is  -- Child Package body OS.File_Manager

   package Internal renames CA11009_0.CA11009_1.CA11009_2;            

   -- These subprograms utilize calls to subprograms contained in a private
   -- sibling to perform the actual processing.

   procedure Create_File (Mode      : in     File_Mode_Type;
                          File_Key  :    out File_Descriptor_Type) is
   begin
      File_Key := Internal.Create (Mode);
   end Create_File;

end CA11009_0.CA11009_1;        -- Child Package body OS.File_Manager
