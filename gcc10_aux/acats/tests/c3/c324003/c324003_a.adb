

package body C324003_A is

   pragma Assertion_Policy (Check); -- Should turn on for all

   procedure Close (File : in out File_Type) is
   begin

      File.Open := False;
      File.Mode := In_File;

   end Close;

   function Is_Open (Open_File : File_Type) return Boolean is
   begin

      return Open_File.Open;

   end Is_Open;

   function Mode (File : Open_File_Type) return File_Mode is
   begin

      return File.Mode;

   end Mode;

   function Name (File : in Open_File_Type) return String is
   begin

      return "No Names"; -- No file names in this example.

   end Name;

   procedure Open (File : in out File_Type;
                   Mode : in     File_Mode) is
   begin

      File.Open := True;
      File.Mode := Mode;

   end Open;

   procedure Get (File : in Input_File_Type; Item : out Character) is
   begin

      Item := 'X';

   end Get;

   procedure Put (File : in Output_File_Type; Item : in Character) is

      My_Item : Character;

   begin

      My_Item := Item;

   end Put;

end C324003_A;
