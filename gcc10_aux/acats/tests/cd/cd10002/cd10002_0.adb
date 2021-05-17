

package body CD10002_0 is

    package body Nonlimited_Stream_Ops is
        Cnts : Counts := (others => 0);
        X : T; -- Initialized by Write/Output.

        procedure Write (Stream : access Root_Stream_Type'Class; Item : T) is
        begin
            X := Item;
            Cnts (Write) := Cnts (Write) + 1;
        end Write;

        function Input (Stream : access Root_Stream_Type'Class) return T is
        begin
            Cnts (Input) := Cnts (Input) + 1;
            return X;
        end Input;

        procedure Read (Stream : access Root_Stream_Type'Class; Item : out T) is
        begin
            Cnts (Read) := Cnts (Read) + 1;
            Item := X;
        end Read;

        procedure Output (Stream : access Root_Stream_Type'Class; Item : T) is
        begin
            X := Item;
            Cnts (Output) := Cnts (Output) + 1;
        end Output;

        function Get_Counts return Counts is
        begin
            return Cnts;
        end Get_Counts;

    end Nonlimited_Stream_Ops;

    package body Limited_Stream_Ops is
        Cnts : Counts := (others => 0);

        procedure Write (Stream : access Root_Stream_Type'Class; Item : T) is
        begin
            Cnts (Write) := Cnts (Write) + 1;
        end Write;

        function Input (Stream : access Root_Stream_Type'Class) return T is
        begin
            Cnts (Input) := Cnts (Input) + 1;
            return C : T; -- Default initialized.
        end Input;

        procedure Read (Stream : access Root_Stream_Type'Class; Item : out T) is
        begin
            Cnts (Read) := Cnts (Read) + 1;
        end Read;

        procedure Output (Stream : access Root_Stream_Type'Class; Item : T) is
        begin
            Cnts (Output) := Cnts (Output) + 1;
        end Output;

        function Get_Counts return Counts is
        begin
            return Cnts;
        end Get_Counts;

    end Limited_Stream_Ops;

end CD10002_0;
