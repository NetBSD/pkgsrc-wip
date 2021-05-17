
with Ada.Streams.Stream_IO;
package body CXAC009_Logger is

   File : Ada.Streams.Stream_IO.File_Type;
      -- This declaration would be illegal if the type doesn't have
      -- Preelaborable_Initialization.

   procedure Open_Log (Log_Name : in String) is
      -- Open the log file Log_Name.
   begin
      Ada.Streams.Stream_IO.Open (File,
                                  Ada.Streams.Stream_IO.Append_File,
                                  Log_Name);
   end Open_Log;


   procedure Close_Log is
      -- Close the log file.
   begin
      Ada.Streams.Stream_IO.Close (File);
   end Close_Log;


   procedure Log_Item (Item : in String) is
      use type Ada.Streams.Stream_Element_Offset;
      Buffer : Ada.Streams.Stream_Element_Array(1 .. Item'Length + 2);
   begin
      for I in Item'range loop
         Buffer(Ada.Streams.Stream_Element_Offset(I - Item'First)+1) :=
            Ada.Streams.Stream_Element(Character'Pos(Item(I)));
      end loop;
      Buffer(Buffer'Last-1) := 13;
      Buffer(Buffer'Last  ) := 10;
      Ada.Streams.Stream_IO.Write (File, Buffer);
   end Log_Item;

end CXAC009_Logger;
