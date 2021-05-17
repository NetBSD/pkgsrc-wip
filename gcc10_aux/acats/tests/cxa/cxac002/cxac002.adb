

with Ada.Streams.Stream_IO, CXAC002_0, Report;
procedure CXAC002 is
   Filter_File     : Ada.Streams.Stream_IO.File_Type;
   Filter_Stream   : Ada.Streams.Stream_IO.Stream_Access;
   Filter_Filename : constant String :=
                              Report.Legal_File_Name ( Nam => "CXAC002" );
   Incomplete : Exception;

begin

   Report.Test ("CXAC002", "Check that the subprograms defined in "         &
                           "package Ada.Streams.Stream_IO are accessible, " &
                           "and that they provide the appropriate "         &
                           "functionality");

   Test_for_Stream_IO_Support:

   begin

      -- If an implementation does not support Stream_IO in a particular
      -- environment, the exception Use_Error or Name_Error will be raised on
      -- calls to various Stream_IO operations.  This block statement
      -- encloses a call to Create, which should produce an exception in a
      -- non-supportive environment.  These exceptions will be handled to
      -- produce a Not_Applicable result.

      Ada.Streams.Stream_IO.Create (Filter_File,                    -- Create.
                                    Ada.Streams.Stream_IO.Out_File,
                                    Filter_Filename);
   exception

       when Ada.Streams.Stream_IO.Use_Error | Ada.Streams.Stream_IO.Name_Error =>
          Report.Not_Applicable
             ( "Files not supported - Create as Out_File for Stream_IO" );
          raise Incomplete;

   end Test_for_Stream_IO_Support;

   Operational_Test_Block:
   declare

      use CXAC002_0;
      use type Ada.Streams.Stream_IO.File_Mode;
      use type Ada.Streams.Stream_IO.Count;

      File_Size  : Ada.Streams.Stream_IO.Count :=            -- Count.
        Ada.Streams.Stream_IO.Count'First;                   -- (0)
      File_Index : Ada.Streams.Stream_IO.Positive_Count :=   -- Pos. Count.
        Ada.Streams.Stream_IO.Positive_Count'First;          -- (1)

      First_String  : constant String := "this is going to be ";
      Second_String : constant String := "the best year of your life";
      Total_Length  : constant Natural := First_String'Length +
                                          Second_String'Length;
      Current_Char  : Character := ' ';

      Cap_String    : String (1..Total_Length) := (others => ' ');

      TC_Capital_String : constant String :=
                "THIS IS GOING TO BE THE BEST YEAR OF YOUR LIFE";

   begin

      if not Ada.Streams.Stream_IO.Is_Open (Filter_File) then   -- Is_Open
         Report.Failed ("File not open following Create");
      end if;

      -- Call function Find to determine if the filename (Sub) is contained
      -- in the result of Function Name.

      if not Find(Str => Ada.Streams.Stream_IO.Name(Filter_File), -- Name.
                  Sub => Filter_Filename)
      then
         Report.Failed ("Function Name provided incorrect filename");
      end if;
                                                                 -- Stream.
      Filter_Stream := Ada.Streams.Stream_IO.Stream (Filter_File);

      ---

      Enter_Data_In_Stream:
      declare
         Pos                 : Natural := 1;
         Bad_Character_Found : Boolean := False;
      begin

         -- Enter data from the first string into the stream.
         while Pos <= Natural(First_String'Length) loop
            -- Write all characters of the First_String to the stream.
            Character'Write (Filter_Stream, First_String (Pos));
            Pos := Pos + 1;
            -- Ensure data put in file on a regular basis.
            if Pos mod 5 = 0 then
               Ada.Streams.Stream_IO.Flush (Filter_File);         -- Flush.
            end if;
         end loop;

         Ada.Streams.Stream_IO.Flush (Filter_File);               -- Flush.
         -- Reset to In_File mode and read stream contents.
         Reset1:
         begin
            Ada.Streams.Stream_IO.Reset (Filter_File,                -- Reset.
                                         Ada.Streams.Stream_IO.In_File);
         exception
            when Ada.Streams.Stream_IO.Use_Error =>
               Report.Not_Applicable
                  ( "Reset to In_File not supported for Stream_IO" );
               raise Incomplete;
         end Reset1;

         Pos := 1;
         while Pos <= First_String'Length loop
            -- Read one character from the stream.
            Character'Read (Filter_Stream, Current_Char);         -- 'Read
            -- Verify character against the original string.
            if Current_Char /= First_String(Pos) then
               Bad_Character_Found := True;
            end if;
            Pos := Pos + 1;
         end loop;

         if Bad_Character_Found then
            Report.Failed ("Incorrect character read from stream");
         end if;

         -- Following user stream/string processing, the stream file is
         -- appended to as follows:

         Reset2:
         begin
            Ada.Streams.Stream_IO.Reset (Filter_File,                -- Reset.
                                         Ada.Streams.Stream_IO.Append_File);
         exception
            when Ada.Streams.Stream_IO.Use_Error =>
               Report.Not_Applicable
                  ( "Reset to Append_File not supported for Stream_IO" );
               raise Incomplete;
         end Reset2;

         if Ada.Streams.Stream_IO.Mode (Filter_File) /=           -- Mode.
            Ada.Streams.Stream_IO.Append_File
         then
            Report.Failed ("Incorrect mode following Reset to Append");
         end if;

         Pos := 1;
         while Pos <= Natural(Second_String'Length) loop
            -- Write all characters of the Second_String to the stream.
            Character'Write (Filter_Stream, Second_String (Pos)); -- 'Write
            Pos := Pos + 1;
         end loop;

         Ada.Streams.Stream_IO.Flush (Filter_File);               -- Flush.

         -- Record file statistics.
         File_Size  := Ada.Streams.Stream_IO.Size  (Filter_File); -- Size.

         Index_Might_Not_Be_Supported:
         begin
            File_Index := Ada.Streams.Stream_IO.Index (Filter_File); -- Index.
         exception
            when Ada.Streams.Stream_IO.Use_Error =>
               Report.Not_Applicable ( "Index not supported for Stream_IO" );
               raise Incomplete;
         end Index_Might_Not_Be_Supported;

      exception
         when Incomplete =>
            raise;
         when others =>
            Report.Failed ("Exception in Enter_Data_In_Stream block");
            raise;
      end Enter_Data_In_Stream;

      ---

      Filter_Block:
      declare
         Pos          : Positive := 1;
         Full_String  : constant String := First_String & Second_String;

         function Capitalize (Char : Character) return Character is
         begin
            if Char /= ' ' then
               return Character'Val( Character'Pos(Char) -
                      (Character'Pos('a') - Character'Pos('A')));
            else
               return Char;
            end if;
         end Capitalize;

      begin

         Reset3:
         begin
           Ada.Streams.Stream_IO.Reset (Filter_File,                -- Reset.
                                         Ada.Streams.Stream_IO.In_File);
         exception
            when Ada.Streams.Stream_IO.Use_Error =>
               Report.Not_Applicable
                  ( "Reset to In_File not supported for Stream_IO" );
               raise Incomplete;
         end Reset3;

         if Ada.Streams.Stream_IO.Mode (Filter_File) /=           -- Mode.
            Ada.Streams.Stream_IO.In_File
         then
            Report.Failed ("Incorrect mode following Reset to In_File");
         end if;

         if not Ada.Streams.Stream_IO.Is_Open (Filter_File) then -- Is_Open
            Report.Failed ( "Reset command did not leave file open" );
         end if;

         if Ada.Streams.Stream_IO.Size (Filter_File) /=            -- Size.
            File_Size
         then
            Report.Failed ("Reset file is not correct size");
         end if;

         if Ada.Streams.Stream_IO.Index (Filter_File) /= 1 then    -- Index.
            -- File position should have been reset to start of file.
            Report.Failed ("Index of file not set to 1 following Reset");
         end if;

         while Pos <= Full_String'Length loop
            -- Read one character from the stream.
            Character'Read (Filter_Stream, Current_Char);          -- 'Read
            -- Verify character against the original string.
            if Current_Char /= Full_String(Pos) then
               Report.Failed ("Incorrect character read from stream");
            else
               -- Capitalize the characters read from the stream, and
               -- place them in a string variable.
               Cap_String(Pos) := Capitalize (Current_Char);
            end if;
            Pos := Pos + 1;
         end loop;

         -- File index should now be set to the position following the final
         -- character in the file (the same as the index value stored at
         -- the completion of the Enter_Data_In_Stream block).
         if Ada.Streams.Stream_IO.Index (Filter_File) /=           -- Index.
            File_Index
         then
            Report.Failed ("Incorrect file index position");
         end if;

         -- The stream file should now be at EOF.                  -- EOF.
         if not Ada.Streams.Stream_IO.End_Of_File (Filter_File) then
            Report.Failed ("File not empty following filtering");
         end if;

      exception

         when Incomplete =>
            raise;
         when others =>
            Report.Failed ("Exception in Filter_Block");
            raise;
      end Filter_Block;

         ---

      Verification_Block:
      begin

         -- Verify that the entire string was examined, and that the
         -- process of capitalizing the character data was successful.
         if Cap_String /= TC_Capital_String then
            Report.Failed ("Incorrect Capitalization");
         end if;

      exception
         when others =>
            Report.Failed ("Exception in Verification_Block");
      end Verification_Block;


   exception

         when Incomplete =>
            raise;
         when others =>
            Report.Failed ("Exception raised in Operational Test Block");

   end Operational_Test_Block;

   Deletion:
   begin
      if Ada.Streams.Stream_IO.Is_Open (Filter_File) then          -- Is_Open.
         Ada.Streams.Stream_IO.Delete (Filter_File);               -- Delete.
      else
         Ada.Streams.Stream_IO.Open (Filter_File,                  -- Open.
                                     Ada.Streams.Stream_IO.Out_File,
                                     Filter_Filename);
         Ada.Streams.Stream_IO.Delete (Filter_File);               -- Delete.
      end if;
   exception
      when others =>
         Report.Failed
            ( "Delete not properly implemented for Stream_IO" );
   end Deletion;

   Report.Result;

exception
   when Incomplete =>
      Report.Result;
   when others     =>
      Report.Failed ( "Unexpected exception" );
      Report.Result;

end CXAC002;
