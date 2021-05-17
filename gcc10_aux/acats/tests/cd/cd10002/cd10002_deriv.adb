

package body CD10002_Deriv is

    function Is_Odd (X : Integer) return T1 is
    begin
        return True;
    end Is_Odd;
    procedure Print (X : T2) is
    begin
        null;
    end Print;
    function "+" (L, R : T3) return T3 is
    begin
        return (False => L (False) + R (True), True => L (True) + R (False));
    end "+";
    task body T4 is
    begin
        null;
    end T4;
    protected body T5 is
    end T5;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt1'Base)
       renames Nt1_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt1'Base
       renames Nt1_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt1'Base)
       renames Nt1_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt1'Base)
       renames Nt1_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt2)
       renames Nt2_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt2
       renames Nt2_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt2)
       renames Nt2_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt2)
       renames Nt2_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt3)
       renames Nt3_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt3
       renames Nt3_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt3)
       renames Nt3_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt3)
       renames Nt3_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt4)
       renames Nt4_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt4
       renames Nt4_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt4)
       renames Nt4_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt4)
       renames Nt4_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt5)
       renames Nt5_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt5
       renames Nt5_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt5)
       renames Nt5_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt5)
       renames Nt5_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt6)
       renames Nt6_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt6
       renames Nt6_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt6)
       renames Nt6_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt6)
       renames Nt6_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt7)
       renames Nt7_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt7
       renames Nt7_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt7)
       renames Nt7_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt7)
       renames Nt7_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt8)
       renames Nt8_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt8
       renames Nt8_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt8)
       renames Nt8_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt8)
       renames Nt8_Ops.Output;

end CD10002_Deriv;
