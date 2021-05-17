

with Ada.Streams;
use Ada.Streams;
package CD10002_1 is

    type Dummy_Stream is new Root_Stream_Type with null record;
    procedure Read (Stream : in out Dummy_Stream;
                    Item : out Stream_Element_Array;
                    Last : out Stream_Element_Offset);
    procedure Write (Stream : in out Dummy_Stream;
                     Item : Stream_Element_Array);

end CD10002_1;
