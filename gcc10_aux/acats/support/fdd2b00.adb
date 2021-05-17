

package body FDD2B00 is

   procedure Read (
      Stream : in out Channel_Type;
      Item   : out Ada.Streams.Stream_Element_Array;
      Last   : out Ada.Streams.Stream_Element_Offset) is
      use type Ada.Streams.Stream_Element_Offset;
   begin
      if Stream.Count <= Item'Length then
         Last := Item'First + Stream.Count - 1;
         Item(Item'First .. Last) := Stream.Buffer(1 .. Stream.Count);
         Stream.Count := 0;
      else
         Last := Item'Last;
         Item := Stream.Buffer(1 .. Item'Length);
         Stream.Count := Stream.Count - Item'Length;
         Stream.Buffer(1 .. Stream.Count) :=
             Stream.Buffer(Item'Length + 1 .. Stream.Count + Item'Length);
      end if;
   end Read;


   procedure Write (
      Stream : in out Channel_Type;
      Item   : in Ada.Streams.Stream_Element_Array) is
      use type Ada.Streams.Stream_Element_Offset;
   begin
      if Stream.Count + Item'Length > 100 then
         raise Constraint_Error with "Buffer full";
      end if;
      Stream.Buffer (Stream.Count + 1 .. Stream.Count + Item'Length) :=
         Item;
      Stream.Count := Stream.Count + Item'Length;
   end Write;


   function Element_Count (Stream : Channel_Type)
      return Ada.Streams.Stream_Element_Count is
   begin
      return Stream.Count;
   end Element_Count;


   procedure Clear (Stream : in out Channel_Type) is
   begin
      Stream.Count := 0;
   end Clear;

end FDD2B00;



