
     --=================================================================--

with Report;
with CA11002_0.CA11002_1;          -- Child package OS.Operations.
with CA11002_0.CA11002_2;          -- Child subprogram OS.Convert_File_Mode,
                                   -- Implicitly with parent, OS.
use CA11002_0;                     -- All user-defined operators directly
                                   -- visible.
procedure CA11002 is
begin

   Report.Test ("CA11002", "Check that a public child can utilize its " &
                "parent unit's visible definitions");

   File_Creation:                   -- This processing block will demonstrate
                                    -- use of child package subroutine that
                                    -- takes advantage of components declared
                                    -- in the parent package.
   declare
      User_File : File_Type;
   begin
      CA11002_0.CA11002_1.Create_File (File => User_File); -- Default mode
                                                           -- parameter used in
                                                           -- this call.
      if (User_File.Descriptor = System_File.Descriptor) or
         (User_File.Mode       = Default_Mode) 
      then
         Report.Failed ("Incorrect file creation");
      end if;

   end File_Creation;

   --------------------------------------------------------------
   File_Mode_Conversion:            -- This processing block will demonstrate
                                    -- the occurrence of a (forced) exception
                                    -- being raised in a child subprogram, and
                                    -- propagated to the caller.  The exception
                                    -- is handled, and the child subprogram
                                    -- is called again, this time to perform
                                    -- without error.
   declare
      procedure Convert_File_Mode (File : in out File_Type; 
        New_Mode : in File_Mode) renames CA11002_0.CA11002_2; 
      New_File : File_Type;
   begin                               -- Raise an exception with this
                                       -- illegal conversion operation
                                       -- (attempt to change to current mode).

      Convert_File_Mode (File     => New_File,
                         New_Mode => Default_Mode);
      Report.Failed ("Exception should have been raised in child unit");

   exception
      when File_Mode_Error =>          -- Perform the conversion again, this
                                       -- time with a different file mode.

         Convert_File_Mode (File     => New_File,
                            New_Mode => CA11002_0.Active_Mode);

         if New_File.Mode /= Read_Write then
            Report.Failed ("Incorrect result from mode conversion operation");
         end if;

      when others =>
         Report.Failed ("Unexpected exception raised in File_Mode_Conversion");

   end File_Mode_Conversion;

   Report.Result;

end CA11002;
