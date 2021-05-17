package body FDD2A00 is

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


    package body Counting_Stream_Ops is
        Cnts : Counts := (others => 0);

        procedure Write (Stream : access Root_Stream_Type'Class; Item : T) is
        begin
            Cnts (Write) := Cnts (Write) + 1;
            Actual_Write (Stream, Item);
        end Write;

        function Input (Stream : access Root_Stream_Type'Class) return T is
        begin
            Cnts (Input) := Cnts (Input) + 1;
            return Actual_Input (Stream);
        end Input;

        procedure Read (Stream : access Root_Stream_Type'Class; Item : out T) is
        begin
            Cnts (Read) := Cnts (Read) + 1;
            Actual_Read (Stream, Item);
        end Read;

        procedure Output (Stream : access Root_Stream_Type'Class; Item : T) is
        begin
            Cnts (Output) := Cnts (Output) + 1;
            Actual_Output (Stream, Item);
        end Output;

        function Get_Counts return Counts is
        begin
            return Cnts;
        end Get_Counts;

    end Counting_Stream_Ops;

end FDD2A00;
