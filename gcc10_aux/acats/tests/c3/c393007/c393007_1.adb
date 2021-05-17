 
 package body C393007_1 is
   use type C393007_0.Log_File_Type;
 
   procedure Handle (A : in out Normal_Alert_Type) is   
     begin
       Set_Time (A);
       Log (A, Log_File);
     end Handle;
 
   procedure Log    (A : Normal_Alert_Type;      
                     L : in out C393007_0.Log_File_Type) is
      begin
        L := C393007_0."+"(L, 1);
      end Log;
   
 end C393007_1;
