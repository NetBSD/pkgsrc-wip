
     --==================================================================--

separate (CA13003_0)
package body CA13003_2 is

   procedure CA13003_3 is separate;                 -- Open files
   function CA13003_4 (ID_In : File_ID; File_In : File_Rec) 
     return File_Name is separate;                  -- Process files
   package body CA13003_5 is separate;              -- Generate report

end CA13003_2;
