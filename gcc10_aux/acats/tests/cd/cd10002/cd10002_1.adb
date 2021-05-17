

with Report;
use Report;
package body CD10002_1 is

    procedure Read (Stream : in out Dummy_Stream;
                    Item : out Stream_Element_Array;
                    Last : out Stream_Element_Offset) is
    begin
        Failed ("Unexpected call to the Read operation of Dummy_Stream");
    end Read;

    procedure Write (Stream : in out Dummy_Stream;
                     Item : Stream_Element_Array) is
    begin
        Failed ("Unexpected call to the Write operation of Dummy_Stream");
    end Write;

end CD10002_1;
