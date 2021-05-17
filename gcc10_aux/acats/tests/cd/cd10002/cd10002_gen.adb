

package body CD10002_Gen is

    use CD10002_0;

    Nt10_Cnts : Counts := (others => 0);
    Nt12_Cnts : Counts := (others => 0);

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt1'Base)
       renames Nt1_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt1'Base
       renames Nt1_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt1'Base)
       renames Nt1_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt1'Base)
       renames Nt1_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt2'Base)
       renames Nt2_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt2'Base
       renames Nt2_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt2'Base)
       renames Nt2_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt2'Base)
       renames Nt2_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt3'Base)
       renames Nt3_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt3'Base
       renames Nt3_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt3'Base)
       renames Nt3_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt3'Base)
       renames Nt3_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt4'Base)
       renames Nt4_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt4'Base
       renames Nt4_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt4'Base)
       renames Nt4_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt4'Base)
       renames Nt4_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt5'Base)
       renames Nt5_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt5'Base
       renames Nt5_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt5'Base)
       renames Nt5_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt5'Base)
       renames Nt5_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt6'Base)
       renames Nt6_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt6'Base
       renames Nt6_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt6'Base)
       renames Nt6_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt6'Base)
       renames Nt6_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt7)
       renames Nt7_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt7
       renames Nt7_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt7)
       renames Nt7_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt7)
       renames Nt7_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt8'Base)
       renames Nt8_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt8'Base
       renames Nt8_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt8'Base)
       renames Nt8_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt8'Base)
       renames Nt8_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt9)
       renames Nt9_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt9
       renames Nt9_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt9)
       renames Nt9_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt9)
       renames Nt9_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt10) is
    begin
        Nt10_Cnts (Write) := Nt10_Cnts (Write) + 1;
    end Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt10 is
    begin
        Nt10_Cnts (Input) := Nt10_Cnts (Input) + 1;
        return C : Nt10; -- Default-initialized.
    end Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt10) is
    begin
        Nt10_Cnts (Read) := Nt10_Cnts (Read) + 1;
    end Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt10) is
    begin
        Nt10_Cnts (Output) := Nt10_Cnts (Output) + 1;
    end Output;
    function Get_Nt10_Counts return CD10002_0.Counts is
    begin
        return Nt10_Cnts;
    end Get_Nt10_Counts;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt11)
       renames Nt11_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt11
       renames Nt11_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt11)
       renames Nt11_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt11)
       renames Nt11_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt12) is
    begin
        Nt12_Cnts (Write) := Nt12_Cnts (Write) + 1;
    end Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt12 is
    begin
        Nt12_Cnts (Input) := Nt12_Cnts (Input) + 1;
        return C : Nt12; -- Default-initialized.
    end Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt12) is
    begin
        Nt12_Cnts (Read) := Nt12_Cnts (Read) + 1;
    end Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt12) is
    begin
        Nt12_Cnts (Output) := Nt12_Cnts (Output) + 1;
    end Output;
    function Get_Nt12_Counts return CD10002_0.Counts is
    begin
        return Nt12_Cnts;
    end Get_Nt12_Counts;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : Nt13)
       renames Nt13_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return Nt13
       renames Nt13_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out Nt13)
       renames Nt13_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : Nt13)
       renames Nt13_Ops.Output;

end CD10002_Gen;
