
     --=================================================================--

with Report;
package body CA11002_0.CA11002_1 is       -- Child package body OS.Operations.

   function New_File_Validated (File : File_Type)        -- Ensure that a newly
     return Boolean is                                   -- created file has
      Result : Boolean := False;                         -- appropriate values.
   begin                                                 
      if (File.Descriptor > System_File.Descriptor) and  -- Parent object.
         (File.Mode  in  File_Mode )                     -- Parent type.
      then
         Result := True;
      end if;

      return (Result);

   end New_File_Validated;
   --------------------------------------------------------------
   procedure Create_File 
     (Mode       : in     File_Mode := Active_Mode;     -- Parent constant.
      File       :    out File_Type) is                 -- Parent type.

      New_File : File_Type;

   begin
      New_File.Descriptor := Next_Available_File;       -- Parent subprogram.
      New_File.Mode       := Mode;

      if New_File_Validated (File => New_File) then
         File := New_File;
      end if;

   end Create_File;

end CA11002_0.CA11002_1;                  -- Child Package body OS.Operations.
