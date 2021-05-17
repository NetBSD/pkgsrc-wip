

with Ada.Streams;
use Ada.Streams;
with Report;
use Report;
with System;
with CD10002_0;
with CD10002_1;
with CD10002_Deriv;
with CD10002_Gen;
with CD10002_Priv;
procedure CD10002 is

    package Deriv renames CD10002_Deriv;
    generic package Gen renames CD10002_Gen;
    package Priv renames CD10002_Priv;

    type Stream_Ops is (Read, Write, Input, Output);
    type Counts is array (Stream_Ops) of Natural;

    S : aliased CD10002_1.Dummy_Stream;

begin
    Test ("CD10002",
          "Check that operational items are allowed in some contexts " &
             "where representation items are not");

    Test_Priv:
        declare
            X1 : Priv.T1;
            X2 : Priv.T2;
            use CD10002_0;
        begin
            Comment
               ("Check that the name of an incompletely defined type can be " &
                "used when specifying an operational item");

            -- Partial view of a private type.
            Priv.T1'Write (S'Access, X1);
            Priv.T1'Read (S'Access, X1);
            Priv.T1'Output (S'Access, X1);
            X1 := Priv.T1'Input (S'Access);

            if Priv.Get_T1_Counts /= (1, 1, 1, 1) then
                Failed ("Incorrect calls to the stream attributes for Priv.T1");
            elsif Priv.T1'External_Tag /= Priv.External_Tag_1 then
                Failed ("Incorrect external tag for Priv.T1");
            end if;

            -- Incompletely defined but not private.
            Priv.T2'Write (S'Access, X2);
            Priv.T2'Read (S'Access, X2);
            Priv.T2'Output (S'Access, X2);
            X2 := Priv.T2'Input (S'Access);

            if Priv.Get_T2_Counts /= (1, 1, 1, 1) then
                Failed ("Incorrect calls to the stream attributes for Priv.T2");
            elsif Priv.T2'External_Tag /= Priv.External_Tag_2 then
                Failed ("Incorrect external tag for Priv.T2");
            end if;

        end Test_Priv;

    Test_Gen:
        declare

            type Modular is mod System.Max_Binary_Modulus;
            type Decimal is delta 1.0 digits 1;
            type Access_Modular is access Modular;
            type R9 is null record;
            type R10 (D : access Integer := new Integer'(4)) is
                         limited null record;
            type Arr is array (Character) of Integer;

            package Inst is new Gen (T1 => Character,
                                     T2 => Integer,
                                     T3 => Modular,
                                     T4 => Float,
                                     T5 => Duration,
                                     T6 => Decimal,
                                     T7 => Access_Modular,
                                     T8 => Boolean,
                                     T9 => R9,
                                     T10 => R10,
                                     T11 => Arr);

            X1 : Inst.Nt1 := 'a';
            X2 : Inst.Nt2 := 0;
            X3 : Inst.Nt3 := 0;
            X4 : Inst.Nt4 := 0.0;
            X5 : Inst.Nt5 := 0.0;
            X6 : Inst.Nt6 := 0.0;
            X7 : Inst.Nt7 := null;
            X8 : Inst.Nt8 := Inst.False;
            X9 : Inst.Nt9 := (null record);
            X10 : Inst.Nt10 (D => new Integer'(5));
            Y10 : Integer;
            X11 : Inst.Nt11 := (others => 0);
            X12 : Inst.Nt12 (D => new Integer'(7));
            Y12 : Integer;
            X13 : Inst.Nt13 := (others => 0);
            use CD10002_0;
        begin
            Comment ("Check that operational items can be specified for a " &
                     "descendant of a generic formal untagged type");

            Inst.Nt1'Write (S'Access, X1);
            Inst.Nt1'Read (S'Access, X1);
            Inst.Nt1'Output (S'Access, X1);
            X1 := Inst.Nt1'Input (S'Access);

            if Inst.Nt1_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt1");
            end if;

            Inst.Nt2'Write (S'Access, X2);
            Inst.Nt2'Read (S'Access, X2);
            Inst.Nt2'Output (S'Access, X2);
            X2 := Inst.Nt2'Input (S'Access);

            if Inst.Nt2_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt2");
            end if;

            Inst.Nt3'Write (S'Access, X3);
            Inst.Nt3'Read (S'Access, X3);
            Inst.Nt3'Output (S'Access, X3);
            X3 := Inst.Nt3'Input (S'Access);

            if Inst.Nt3_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt3");
            end if;

            Inst.Nt4'Write (S'Access, X4);
            Inst.Nt4'Read (S'Access, X4);
            Inst.Nt4'Output (S'Access, X4);
            X4 := Inst.Nt4'Input (S'Access);

            if Inst.Nt4_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt4");
            end if;

            Inst.Nt5'Write (S'Access, X5);
            Inst.Nt5'Read (S'Access, X5);
            Inst.Nt5'Output (S'Access, X5);
            X5 := Inst.Nt5'Input (S'Access);

            if Inst.Nt5_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt5");
            end if;

            Inst.Nt6'Write (S'Access, X6);
            Inst.Nt6'Read (S'Access, X6);
            Inst.Nt6'Output (S'Access, X6);
            X6 := Inst.Nt6'Input (S'Access);

            if Inst.Nt6_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt6");
            end if;

            Inst.Nt7'Write (S'Access, X7);
            Inst.Nt7'Read (S'Access, X7);
            Inst.Nt7'Output (S'Access, X7);
            X7 := Inst.Nt7'Input (S'Access);

            if Inst.Nt7_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt7");
            end if;

            Inst.Nt8'Write (S'Access, X8);
            Inst.Nt8'Read (S'Access, X8);
            Inst.Nt8'Output (S'Access, X8);
            X8 := Inst.Nt8'Input (S'Access);

            if Inst.Nt8_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt8");
            end if;

            Inst.Nt9'Write (S'Access, X9);
            Inst.Nt9'Read (S'Access, X9);
            Inst.Nt9'Output (S'Access, X9);
            X9 := Inst.Nt9'Input (S'Access);

            if Inst.Nt9_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt9");
            end if;

            Inst.Nt10'Write (S'Access, X10);
            Inst.Nt10'Read (S'Access, X10);
            Inst.Nt10'Output (S'Access, X10);
            Y10 := Inst.Nt10'Input (S'Access).D.all;

            if Inst.Get_Nt10_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt10");
            end if;

            Inst.Nt11'Write (S'Access, X11);
            Inst.Nt11'Read (S'Access, X11);
            Inst.Nt11'Output (S'Access, X11);
            X11 := Inst.Nt11'Input (S'Access);

            if Inst.Nt11_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt11");
            end if;

            Inst.Nt12'Write (S'Access, X12);
            Inst.Nt12'Read (S'Access, X12);
            Inst.Nt12'Output (S'Access, X12);
            Y12 := Inst.Nt12'Input (S'Access).D.all;

            if Inst.Get_Nt12_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt12");
            end if;

            Inst.Nt13'Write (S'Access, X13);
            Inst.Nt13'Read (S'Access, X13);
            Inst.Nt13'Output (S'Access, X13);
            X13 := Inst.Nt13'Input (S'Access);

            if Inst.Nt13_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Inst.Nt13");
            end if;
        end Test_Gen;

    Test_Deriv:
        declare
            X1 : Deriv.Nt1 := Deriv.False;
            X2 : Deriv.Nt2 := (others => 0.0);
            X3 : Deriv.Nt3 := (others => 0.0);
            X4 : Deriv.Nt4;
            Y4 : Boolean;
            X5 : Deriv.Nt5;
            Y5 : System.Address;
            X6 : Deriv.Nt6;
            Y6 : Integer;
            X7 : Deriv.Nt7;
            Y7 : Integer;
            X8 : Deriv.Nt8;
            Y8 : Integer;
            use CD10002_0;
        begin
            Comment ("Check that operational items can be specified for a " &
                     "derived untagged type even if the parent type is a " &
                     "by-reference type, or has user-defined primitive " &
                     "subprograms");

            Deriv.Nt1'Write (S'Access, X1);
            Deriv.Nt1'Read (S'Access, X1);
            Deriv.Nt1'Output (S'Access, X1);
            X1 := Deriv.Nt1'Input (S'Access);

            if Deriv.Nt1_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt1");
            end if;

            Deriv.Nt2'Write (S'Access, X2);
            Deriv.Nt2'Read (S'Access, X2);
            Deriv.Nt2'Output (S'Access, X2);
            X2 := Deriv.Nt2'Input (S'Access);

            if Deriv.Nt2_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt2");
            end if;

            Deriv.Nt3'Write (S'Access, X3);
            Deriv.Nt3'Read (S'Access, X3);
            Deriv.Nt3'Output (S'Access, X3);
            X3 := Deriv.Nt3'Input (S'Access);

            if Deriv.Nt3_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt3");
            end if;

            Deriv.Nt4'Write (S'Access, X4);
            Deriv.Nt4'Read (S'Access, X4);
            Deriv.Nt4'Output (S'Access, X4);
            Y4 := Deriv.Nt4'Input (S'Access)'Terminated;

            if Deriv.Nt4_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt4");
            end if;

            Deriv.Nt5'Write (S'Access, X5);
            Deriv.Nt5'Read (S'Access, X5);
            Deriv.Nt5'Output (S'Access, X5);
            Y5 := Deriv.Nt5'Input (S'Access)'Address;

            if Deriv.Nt5_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt5");
            end if;

            Deriv.Nt6'Write (S'Access, X6);
            Deriv.Nt6'Read (S'Access, X6);
            Deriv.Nt6'Output (S'Access, X6);
            Y6 := Deriv.Nt6'Input (S'Access).D.all;

            if Deriv.Nt6_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt6");
            end if;

            Deriv.Nt7'Write (S'Access, X7);
            Deriv.Nt7'Read (S'Access, X7);
            Deriv.Nt7'Output (S'Access, X7);
            Y7 := Deriv.Nt7'Input (S'Access) ('a').D.all;

            if Deriv.Nt7_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt7");
            end if;

            Deriv.Nt8'Write (S'Access, X8);
            Deriv.Nt8'Read (S'Access, X8);
            Deriv.Nt8'Output (S'Access, X8);
            Y8 := Deriv.Nt8'Input (S'Access)'Size;

            if Deriv.Nt8_Ops.Get_Counts /= (1, 1, 1, 1) then
                Failed
                   ("Incorrect calls to the stream attributes for Deriv.Nt8");
            end if;
        end Test_Deriv;

    Result;
end CD10002;


