
package body CDD2001_0 is

    procedure Clear (Stream : in out My_Stream) is
    begin
	Stream.First := 1;
	Stream.Last := 0;
    end Clear;

    procedure Read (Stream : in out My_Stream;
		    Item : out Stream_Element_Array;
		    Last : out Stream_Element_Offset) is
    begin
	if Item'Length >= Stream.Last - Stream.First + 1 then
	    Item (Item'First .. Item'First + Stream.Last - Stream.First) :=
	       Stream.Contents (Stream.First .. Stream.Last);
	    Last := Item'First + Stream.Last - Stream.First;
	    Stream.First := Stream.Last + 1;
	else
	    Item := Stream.Contents (Stream.First ..
					Stream.First + Item'Length - 1);
	    Last := Item'Last;
	    Stream.First := Stream.First + Item'Length;
	end if;
    end Read;

    procedure Write (Stream : in out My_Stream;
		     Item : in Stream_Element_Array) is
    begin
	Stream.Contents (Stream.Last + 1 .. Stream.Last + Item'Length) := Item;
	Stream.Last := Stream.Last + Item'Length;
    end Write;

end CDD2001_0;
