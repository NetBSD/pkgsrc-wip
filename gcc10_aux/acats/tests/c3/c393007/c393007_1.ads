    -- Alert_System;
 
 --=======================================================================--
 
 with Report;
 with C393007_0;
   -- Alert_system;
 
 package C393007_1 is
 
   type Normal_Alert_Type is   
     new C393007_0.Alert_Type
     with null record;
 
   Log_File: C393007_0.Log_File_Type := C393007_0.Log_File_Type'First;
 
   procedure Handle (A : in out Normal_Alert_Type);  -- Override is required
 
   procedure Log    (A : Normal_Alert_Type;          -- Override is required
                     L : in out C393007_0.Log_File_Type);
 end C393007_1;
