

with Ada.Streams;
use Ada.Streams;
with CD10002_0;
package CD10002_Priv is

    External_Tag_1 : constant String := "Isaac Newton";
    External_Tag_2 : constant String := "Albert Einstein";

    type T1 is tagged private;
    type T2 is tagged
        record
            C : T1;
        end record;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : T1);
    function Input (Stream : access Root_Stream_Type'Class) return T1;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out T1);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : T1);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : T2);
    function Input (Stream : access Root_Stream_Type'Class) return T2;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out T2);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : T2);

    for T1'Write use Write;
    for T1'Input use Input;

    for T2'Read use Read;
    for T2'Output use Output;
    for T2'External_Tag use External_Tag_2;

    function Get_T1_Counts return CD10002_0.Counts;
    function Get_T2_Counts return CD10002_0.Counts;

private

    for T1'Read use Read;
    for T1'Output use Output;
    for T1'External_Tag use External_Tag_1;

    for T2'Write use Write;
    for T2'Input use Input;

    type T1 is tagged null record;

    package T1_Ops is new CD10002_0.Nonlimited_Stream_Ops (T1);
    package T2_Ops is new CD10002_0.Nonlimited_Stream_Ops (T2);

end CD10002_Priv;
