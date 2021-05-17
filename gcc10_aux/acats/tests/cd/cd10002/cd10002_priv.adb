

package body CD10002_Priv is
    procedure Write (Stream : access Root_Stream_Type'Class; Item : T1)
       renames T1_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return T1
       renames T1_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out T1)
       renames T1_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : T1)
       renames T1_Ops.Output;

    procedure Write (Stream : access Root_Stream_Type'Class; Item : T2)
       renames T2_Ops.Write;
    function Input (Stream : access Root_Stream_Type'Class) return T2
       renames T2_Ops.Input;
    procedure Read (Stream : access Root_Stream_Type'Class; Item : out T2)
       renames T2_Ops.Read;
    procedure Output (Stream : access Root_Stream_Type'Class; Item : T2)
       renames T2_Ops.Output;

    function Get_T1_Counts return CD10002_0.Counts renames T1_Ops.Get_Counts;
    function Get_T2_Counts return CD10002_0.Counts renames T2_Ops.Get_Counts;
end CD10002_Priv;
