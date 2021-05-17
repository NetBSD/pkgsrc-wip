

with CXAA017_0; use CXAA017_0;
with Ada.Characters.Latin_1;
with Ada.Exceptions;
with Ada.Text_IO;  
with Report;

procedure CXAA017 is
   
   use Ada.Characters.Latin_1;
   use Ada.Exceptions;
   use Ada.Text_IO;

   Non_Applicable_System : exception;
   No_Reset            : exception;

begin

   Report.Test ("CXAA017", "Check that Ada.Text_IO subprograms "         &
                           "Look_Ahead and Get_Immediate are available " &
                           "and produce correct results");

   Test_Block:
   declare

      User_Input_Ptr    : File_Access := User_Defined_Input_File'Access;

      UDLA_Char,          -- Acronym UDLA => "User Defined Look Ahead"
      UDGI_Char,          -- Acronym UDGI => "User Defined Get Immediate"
      TC_Char           : Character := Ada.Characters.Latin_1.NUL;

      UDLA_End_Of_Line,
      UDGI_Available    : Boolean   := False;

      Char_Pos          : Natural;

      -- This string contains five ISO 646 Control characters and six ISO 646 
      -- Graphic characters:
      TC_String_1  : constant String := STX       & 
                                        SI        & 
                                        DC2       & 
                                        CAN       & 
                                        US        & 
                                        Space     & 
                                        Ampersand & 
                                        Solidus   & 
                                        'A'       & 
                                        LC_X      & 
                                        DEL; 

      -- This string contains two ISO 6429 Control and six ISO 6429 Graphic
      -- characters:
      TC_String_2  : constant String := IS4                         & 
                                        SCI                         & 
                                        Yen_Sign                    & 
                                        Masculine_Ordinal_Indicator & 
                                        UC_I_Grave                  & 
                                        Multiplication_Sign         & 
                                        LC_C_Cedilla                & 
                                        LC_Icelandic_Thorn;

      TC_Number_Of_Strings : constant := 2;

      type String_Access_Type    is access constant String;
      type String_Ptr_Array_Type is 
        array (1..TC_Number_Of_Strings) of String_Access_Type;

      TC_String_Ptr_Array : String_Ptr_Array_Type := 
                              (new String'(TC_String_1),
                               new String'(TC_String_2));



      procedure Create_New_File (The_File : in out File_Type;
                                 Mode     : in     File_Mode;
                                 Next     : in     Integer) is
      begin
         Create (The_File, Mode, Report.Legal_File_Name(Next));
      exception
         -- The following two exceptions can be raised if a system is not
         -- capable of supporting external Text_IO files.  The handler will
         -- raise a user-defined exception which will result in a 
         -- Not_Applicable result for the test.
         when Use_Error | Name_Error => raise Non_Applicable_System;
      end Create_New_File;



      procedure Load_File (The_File : in out File_Type) is
      -- This procedure will load several strings into the file denoted
      -- by the input parameter.  A call to New_Line will add line/page
      -- termination characters, which will be available  for processing
      -- along with the text in the file.
      begin
         Put_Line (The_File, TC_String_Ptr_Array(1).all);
         New_Line (The_File, Spacing => 1);
         Put_Line (The_File, TC_String_Ptr_Array(2).all);
      end Load_File;


   begin

      -- Create user-defined text file that will serve as the appropriate
      -- sources of input to the procedures under test.

      Create_New_File (User_Defined_Input_File, Out_File, 1);

      -- Enter several lines of text into the new input file. 
      -- The characters that make up these text strings will be processed 
      -- using the procedures being exercised in this test.

      Load_File (User_Defined_Input_File);

      -- Check that Mode_Error is raised by Look_Ahead and Get_Immedidate 
      -- if the mode of the file object is not In_File.
      -- Currently, the file mode is Out_File.

      begin
         Look_Ahead(User_Defined_Input_File, UDLA_Char, UDLA_End_Of_Line);
         Report.Failed("Mode_Error not raised by Look_Ahead");
         Report.Comment("This char should never be printed: " & UDLA_Char); 
      exception
         when Mode_Error => null;  -- OK, expected exception.
         when The_Error : others => 
            Report.Failed ("The following exception was raised during the " &
                           "check that Look_Ahead raised Mode_Error when "  &
                           "provided a file object that is not in In_File " &
                           "mode: " & Exception_Name(The_Error));
      end;

      begin
         Get_Immediate(User_Defined_Input_File, UDGI_Char);
         Report.Failed("Mode_Error not raised by Get_Immediate");
         Report.Comment("This char should never be printed: " & UDGI_Char);
      exception
         when Mode_Error => null;  -- OK, expected exception.
         when The_Error : others => 
            Report.Failed ("The following exception was raised during the " &
                           "check that Get_Immediate raised Mode_Error "    &
                           "when provided a file object that is not in "    &
                           "In_File mode: " & Exception_Name(The_Error));
      end;


      -- The file will then be reset to In_File mode to properly function as 
      -- a source of input.

      Reset1:
      begin
         Reset (User_Defined_Input_File, In_File);
      exception
         when Ada.Text_IO.Use_Error =>
            Report.Not_Applicable
               ( "Reset to In_File not supported for Text_IO" );
            raise No_Reset;
      end Reset1;

      -- Process the input file, exercising various Text_IO
      -- functionality, and validating the results at each step.
      -- Note: The designated File_Access object is used in processing
      --       the New_Default_Input_File in the second loop below.

      -- Process characters in first line of text of each file.

      Char_Pos := 1;

      -- Check that the first line is not blank.

      Look_Ahead(User_Defined_Input_File, UDLA_Char, UDLA_End_Of_Line);

      while not UDLA_End_Of_Line loop

         -- Use the Get_Immediate procedure on the file to get the next 
         -- available character on the current line.

         Get_Immediate(User_Defined_Input_File, UDGI_Char);

         -- Check that the characters returned by both procedures are the
         -- same, and that they match the expected character from the file.

         if UDLA_Char /= TC_String_Ptr_Array(1).all(Char_Pos) or
            UDGI_Char /= TC_String_Ptr_Array(1).all(Char_Pos) 
         then
            Report.Failed("Incorrect retrieval of character " &
                          Integer'Image(Char_Pos) & " of first string");
         end if;

         -- Increment the character position counter.
         Char_Pos := Char_Pos + 1;

         -- Check the next character on the line.  If at the end of line,
         -- the processing flow will exit the While loop.

         Look_Ahead(User_Defined_Input_File, UDLA_Char, UDLA_End_Of_Line);

      end loop;

      -- Check to ensure that the "end of line" results returned from the 
      -- Look_Ahead procedure (used to exit the above While loop) corresponds
      -- with the result of Function End_Of_Line.

      if not End_Of_Line(User_Defined_Input_File)
      then
         Report.Failed("Result of procedure Look_Ahead that indicated "    &
                       "being at the end of the line does not correspond " &
                       "with the result of function End_Of_Line");
      end if;

      -- Check that all characters in the string were processed.

      if Char_Pos-1 /= TC_String_1'Length then
         Report.Failed("Not all of the characters on the first line " &
                       "were processed");
      end if;


      -- Call procedure Skip_Line to advance beyond the end of the first line.

      Skip_Line(User_Defined_Input_File);


      -- Process the second line in the file (a blank line).

      Look_Ahead(User_Input_Ptr.all, UDLA_Char, UDLA_End_Of_Line);

      if not UDLA_End_Of_Line then
         Report.Failed("Incorrect end of line determination from procedure " &
                       "Look_Ahead when processing a blank line");
      end if;

      -- Call procedure Skip_Line to advance beyond the end of the second line.

      Skip_Line(User_Input_Ptr.all);


      -- Process characters in the third line of the file (second line 
      -- of text)
      -- Note: The version of Get_Immediate used in processing this line has 
      --       the Boolean parameter Available.

      Char_Pos := 1;

      -- Check whether the line is blank (i.e., at end of line, page, or file).

      Look_Ahead(User_Input_Ptr.all, UDLA_Char, UDLA_End_Of_Line);

      while not UDLA_End_Of_Line loop

         -- Use the Get_Immediate procedure on the file to get access to the
         -- next character on the current line.

         Get_Immediate(User_Input_Ptr.all, UDGI_Char, UDGI_Available);

         -- Check that the Available parameter of Get_Immediate was set
         -- to indicate that a character was available in the file.
         -- Check that the characters returned by both procedures are the 
         -- same, and they all match the expected character from the file.

         if not UDGI_Available                                or
            UDLA_Char /= TC_String_Ptr_Array(2).all(Char_Pos) or
            UDGI_Char /= TC_String_Ptr_Array(2).all(Char_Pos) 
         then
            Report.Failed("Incorrect retrieval of character " &
                          Integer'Image(Char_Pos) & " of second string");
         end if;

         -- Increment the character position counter.

         Char_Pos := Char_Pos + 1;

         -- Check the next character on the line.  If at the end of line,
         -- the processing flow will exit the While loop.

         Look_Ahead(User_Input_Ptr.all, UDLA_Char, UDLA_End_Of_Line);

      end loop;

      -- Check to ensure that the "end of line" results returned from the 
      -- Look_Ahead procedure (used to exit the above While loop) corresponds
      -- with the result of Function End_Of_Line.

      if not End_Of_Line(User_Defined_Input_File)
      then
         Report.Failed("Result of procedure Look_Ahead that indicated "    &
                       "being at the end of the line does not correspond " &
                       "with the result of function End_Of_Line");
      end if;

      -- Check that all characters in the second string were processed.

      if Char_Pos-1 /= TC_String_2'Length then
         Report.Failed("Not all of the characters on the second line " &
                       "were processed");
      end if;


      Deletion:
      begin
         -- Delete the user defined file.

         if Is_Open(User_Defined_Input_File) then
            Delete(User_Defined_Input_File);
         else
            Open(User_Defined_Input_File, Out_File, Report.Legal_File_Name(1));
            Delete(User_Defined_Input_File);
         end if;
      exception
         when others =>
            Report.Failed
               ( "Delete not properly implemented for Text_IO" );
      end Deletion;


   exception

      when No_Reset =>
         null;

      when Non_Applicable_System =>
         Report.Not_Applicable("System not capable of supporting external " &
                               "text files -- Name_Error/Use_Error raised " &
                               "during text file creation");
      when The_Error : others => 
         Report.Failed ("The following exception was raised in the " &
                        "Test_Block: " & Exception_Name(The_Error));
   end Test_Block;

   Report.Result;

end CXAA017;
