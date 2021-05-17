

with Ada.Streams;
use Ada.Streams;
with CD10002_0;
generic
    type T1 is (<>);
    type T2 is range <>;
    type T3 is mod <>;
    type T4 is digits <>;
    type T5 is delta <>;
    type T6 is delta <> digits <>;
    type T7 is access T3;
    type T8 is new Boolean;
    type T9 is private;
    type T10 is limited private; -- Should be self-initializing.
    type T11 is array (T1) of T2;
package CD10002_Gen is

    -- Direct descendants.
    type Nt1 is new T1;
    type Nt2 is new T2;
    type Nt3 is new T3;
    type Nt4 is new T4;
    type Nt5 is new T5;
    type Nt6 is new T6;
    type Nt7 is new T7;
    type Nt8 is new T8;
    type Nt9 is new T9;
    type Nt10 is new T10;
    type Nt11 is new T11;

    -- Indirect descendants (only pick two, a limited one and a non-limited
    -- one).
    type Nt12 is new Nt10;
    type Nt13 is new Nt11;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt1'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt1'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt1'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt1'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt2'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt2'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt2'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt2'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt3'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt3'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt3'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt3'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt4'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt4'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt4'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt4'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt5'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt5'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt5'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt5'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt6'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt6'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt6'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt6'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt7);
    function Input (Stream : access Root_Stream_Type'Class) return Nt7;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt7);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt7);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt8'Base);
    function Input (Stream : access Root_Stream_Type'Class) return Nt8'Base;
    procedure Read (Stream : access Root_Stream_Type'Class;
                    Item : out Nt8'Base);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt8'Base);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt9);
    function Input (Stream : access Root_Stream_Type'Class) return Nt9;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt9);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt9);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt10);
    function Input (Stream : access Root_Stream_Type'Class) return Nt10;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt10);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt10);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt11);
    function Input (Stream : access Root_Stream_Type'Class) return Nt11;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt11);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt11);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt12);
    function Input (Stream : access Root_Stream_Type'Class) return Nt12;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt12);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt12);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt13);
    function Input (Stream : access Root_Stream_Type'Class) return Nt13;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt13);
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt13);

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

    for Nt9'Write use Write;
    for Nt9'Read use Read;
    for Nt9'Output use Output;
    for Nt9'Input use Input;

    for Nt10'Write use Write;
    for Nt10'Read use Read;
    for Nt10'Output use Output;
    for Nt10'Input use Input;

    for Nt11'Write use Write;
    for Nt11'Read use Read;
    for Nt11'Output use Output;
    for Nt11'Input use Input;

    for Nt12'Write use Write;
    for Nt12'Read use Read;
    for Nt12'Output use Output;
    for Nt12'Input use Input;

    for Nt13'Write use Write;
    for Nt13'Read use Read;
    for Nt13'Output use Output;
    for Nt13'Input use Input;

    type Null_Record is null record;

    package Nt1_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt1'Base);
    package Nt2_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt2'Base);
    package Nt3_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt3'Base);
    package Nt4_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt4'Base);
    package Nt5_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt5'Base);
    package Nt6_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt6'Base);
    package Nt7_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt7);
    package Nt8_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt8'Base);
    package Nt9_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt9);
    package Nt11_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt11);
    package Nt13_Ops is new CD10002_0.Nonlimited_Stream_Ops (Nt13);

    function Get_Nt10_Counts return CD10002_0.Counts;
    function Get_Nt12_Counts return CD10002_0.Counts;

end CD10002_Gen;
