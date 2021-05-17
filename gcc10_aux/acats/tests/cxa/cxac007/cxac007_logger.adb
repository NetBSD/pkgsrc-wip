
with Ada.Streams.Stream_IO;
package body CXAC007_Logger is

   procedure Log_Item (To   : in String;
                       Item : in String) is
      File : Ada.Streams.Stream_IO.File_Type;
      use type Ada.Streams.Stream_Element_Offset;
      Buffer : Ada.Streams.Stream_Element_Array(1 .. Item'Length + 2);
   begin
      Ada.Streams.Stream_IO.Open (File,
                                  Ada.Streams.Stream_IO.Append_File,
                                  To);
      for I in Item'range loop
         Buffer(Ada.Streams.Stream_Element_Offset(I - Item'First)+1) :=
            Ada.Streams.Stream_Element(Character'Pos(Item(I)));
      end loop;
      Buffer(Buffer'Last-1) := 13;
      Buffer(Buffer'Last  ) := 10;

      Ada.Streams.Stream_IO.Write (File, Buffer);

      Ada.Streams.Stream_IO.Close (File);

   end Log_Item;

end CXAC007_Logger;
