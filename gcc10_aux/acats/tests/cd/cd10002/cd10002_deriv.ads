

with Ada.Streams;
use Ada.Streams;
with CD10002_0;
package CD10002_Deriv is

    -- Parent has user-defined subprograms.

    type T1 is new Boolean;
    function Is_Odd (X : Integer) return T1;

    type T2 is
        record
            F : Float;
        end record;
    procedure Print (X : T2);

    type T3 is array (Boolean) of Duration;
    function "+" (L, R : T3) return T3;

    -- Parent is by-reference.  No need to check the case where the parent
    -- is tagged, because the defect report only deals with untagged types.

    task type T4 is
    end T4;

    protected type T5 is
    end T5;

    type T6 (D : access Integer := new Integer'(2)) is limited null record;

    type T7 is array (Character) of T6;

    package P is
        type T8 is limited private;
    private
        type T8 is new T5;
    end P;

    type Nt1 is new T1;
    type Nt2 is new T2;
    type Nt3 is new T3;
    type Nt4 is new T4;
    type Nt5 is new T5;
    type Nt6 is new T6;
    type Nt7 is new T7;
    type Nt8 is new P.T8;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt1'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt1'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt1'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt1'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt2);
    function Input (Stream : access Root_Stream_Type'Class) return Nt2;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt2);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt2);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt3);
    function Input (Stream : access Root_Stream_Type'Class) return Nt3;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt3);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt3);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt4);
    function Input (Stream : access Root_Stream_Type'Class) return Nt4;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt4);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt4);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt5);
    function Input (Stream : access Root_Stream_Type'Class) return Nt5;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt5);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt5);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt6);
    function Input (Stream : access Root_Stream_Type'Class) return Nt6;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt6);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt6);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt7);
    function Input (Stream : access Root_Stream_Type'Class) return Nt7;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt7);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt7);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt8);
    function Input (Stream : access Root_Stream_Type'Class) return Nt8;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt8);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt8);

    for Nt1'Write use Write;
    for Nt1'Read use Read;
    for Nt1'Output use Output;
    for Nt1'Input use Input;

    for Nt2'Write use Write;
    for Nt2'Read use Read;
    for Nt2'Output use Output;
    for Nt2'Input use Input;

    for Nt3'Write use Write;
    for Nt3'Read use Read;
    for Nt3'Output use Output;
    for Nt3'Input use Input;

    for Nt4'Write use Write;
    for Nt4'Read use Read;
    for Nt4'Output use Output;
    for Nt4'Input use Input;

    for Nt5'Write use Write;
    for Nt5'Read use Read;
    for Nt5'Output use Output;
    for Nt5'Input use Input;

    for Nt6'Write use Write;
    for Nt6'Read use Read;
    for Nt6'Output use Output;
    for Nt6'Input use Input;

    for Nt7'Write use Write;
    for Nt7'Read use Read;
    for Nt7'Output use Output;
    for Nt7'Input use Input;

    for Nt8'Write use Write;
    for Nt8'Read use Read;
    for Nt8'Output use Output;
    for Nt8'Input use Input;

    package Nt1_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt1'Base);
    package Nt2_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt2);
    package Nt3_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt3);
    package Nt4_Ops is new CD10002_0.Limited_Stream_Ops (Nt4);
    package Nt5_Ops is new CD10002_0.Limited_Stream_Ops (Nt5);
    package Nt6_Ops is new CD10002_0.Limited_Stream_Ops (Nt6);
    package Nt7_Ops is new CD10002_0.Limited_Stream_Ops (Nt7);
    package Nt8_Ops is new CD10002_0.Limited_Stream_Ops (Nt8);

end CD10002_Deriv;
