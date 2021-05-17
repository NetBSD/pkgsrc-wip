
with Ada.Exceptions;
use Ada.Exceptions;
with Ada.Finalization;
with C761011_0;
use C761011_0;
with Report;
use Report;
procedure C761011 is
begin
    Test
       ("C761011",
        " Check that if a finalize propagates an exception, other finalizes " &
         "due to be performed are performed");

    Normal: -- Case 1
        begin
            declare
                Obj1 : Ctrl := Create (Ident_Int (1));
                Obj2 : constant Ctrl := (Ada.Finalization.Controlled with
                                         D => False,
                                         Finalized => Ident_Bool (False),
                                         C1 => Ident_Int (2));
                Obj3 : Ctrl :=
                   (Ada.Finalization.Controlled with
                    D => True,
                    Finalized => Ident_Bool (False),
                    C2 => 2.0 * Float (Ident_Int
                                          (3))); -- Finalization: User_Error
                Obj4 : Ctrl := Create (Ident_Int (4));
            begin
                Comment ("Finalization of normal object");
                Use_It (Obj1); -- Prevent optimization of Objects.
                Use_It (Obj2); -- (Critical if AI-147 is adopted.)
                Use_It (Obj3);
                Use_It (Obj4);
            end;
            Failed ("No exception raised by finalization of normal object");
        exception
            when Program_Error =>
                if not Was_Finalized (Ident_Int (1)) or
                   not Was_Finalized (Ident_Int (2)) or
                   not Was_Finalized (Ident_Int (4)) then
                    Failed ("Missing finalizations - 1");
                end if;
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Message (E) & " - 1");
        end Normal;

    Anon: -- Case 2
        begin
            declare
                Obj1 : Ctrl := (Ada.Finalization.Controlled with
                                D => True,
                                Finalized => Ident_Bool (False),
                                C2 => 2.0 * Float (Ident_Int (5)));
                Obj2 : constant Ctrl := (Ada.Finalization.Controlled with
                                         D => False,
                                         Finalized => Ident_Bool (False),
                                         C1 => Ident_Int (6));
                Obj3 : Ctrl := (Ada.Finalization.Controlled with
                                D => True,
                                Finalized => Ident_Bool (False),
                                C2 => 2.0 * Float (Ident_Int (7)));
                Obj4 : Ctrl := Create (Ident_Int (8));
            begin
                Comment ("Finalization of anonymous object");

                -- The finalization of the anonymous object below will raise
                -- Tasking_Error.
                if Create (Ident_Int (10)).C1 /= Ident_Int (10) then
                    Failed ("Incorrect construction of an anonymous object");
                end if;
                Failed ("Anonymous object not finalized at the end of the " &
                        "enclosing statement");
                Use_It (Obj1); -- Prevent optimization of Objects.
                Use_It (Obj2); -- (Critical if AI-147 is adopted.)
                Use_It (Obj3);
                Use_It (Obj4);
            end;
            Failed ("No exception raised by finalization of an anonymous " &
                    "object of a function");
        exception
            when Program_Error =>
                if not Was_Finalized (Ident_Int (5)) or
                   not Was_Finalized (Ident_Int (6)) or
                   not Was_Finalized (Ident_Int (7)) or
                   not Was_Finalized (Ident_Int (8)) then
                    Failed ("Missing finalizations - 2");
                end if;
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Message (E) & " - 2");
        end Anon;

    An_Exit: -- Case 3
        begin
            for Counter in 1 .. 4 loop
                declare
                    Obj1 : Ctrl := Create (Ident_Int (11));
                    Obj2 : constant Ctrl := (Ada.Finalization.Controlled with
                                             D => False,
                                             Finalized => Ident_Bool (False),
                                             C1 => Ident_Int (12));
                    Obj3 : Ctrl :=
                        (Ada.Finalization.Controlled with
                         D => True,
                         Finalized => Ident_Bool (False),
                         C2 => 2.0 * Float (
                               Ident_Int(13))); -- Finalization: User_Error
                    Obj4 : Ctrl := Create (Ident_Int (14));
                begin
                    Comment ("Finalization because of exit of loop");

                    Use_It (Obj1); -- Prevent optimization of Objects.
                    Use_It (Obj2); -- (Critical if AI-147 is adopted.)
                    Use_It (Obj3);
                    Use_It (Obj4);

                    exit when not Ident_Bool (Obj2.D);

                    Failed ("Exit not taken");
                end;
            end loop;
            Failed ("No exception raised by finalization on exit");
        exception
            when Program_Error =>
                if not Was_Finalized (Ident_Int (11)) or
                   not Was_Finalized (Ident_Int (12)) or
                   not Was_Finalized (Ident_Int (14)) then
                    Failed ("Missing finalizations - 3");
                end if;
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Message (E) & " - 3");
        end An_Exit;

    A_Goto: -- Case 4
        begin
            declare
                Obj1 : Ctrl := Create (Ident_Int (15));
                Obj2 : constant Ctrl := (Ada.Finalization.Controlled with
                                         D => False,
                                         Finalized => Ident_Bool (False),
                                         C1 => Ident_Int (0));
                             -- Finalization: Tasking_Error
                Obj3 : Ctrl := Create (Ident_Int (16));
                Obj4 : Ctrl := (Ada.Finalization.Controlled with
                                D => True,
                                Finalized => Ident_Bool (False),
                                C2 => 2.0 * Float (Ident_Int (17)));
            begin
                Comment ("Finalization because of goto statement");

                Use_It (Obj1); -- Prevent optimization of Objects.
                Use_It (Obj2); -- (Critical if AI-147 is adopted.)
                Use_It (Obj3);
                Use_It (Obj4);

                if Ident_Bool (Obj4.D) then
                   goto Continue;
                end if;

                Failed ("Goto not taken");
            end;
         <<Continue>>
            Failed ("No exception raised by finalization on goto");
        exception
            when Program_Error =>
                if not Was_Finalized (Ident_Int (15)) or
                   not Was_Finalized (Ident_Int (16)) or
                   not Was_Finalized (Ident_Int (17)) then
                    Failed ("Missing finalizations - 4");
                end if;
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Message (E) & " - 4");
        end A_Goto;

    A_Return: -- Case 5
        declare
            procedure Do_Something is
                Obj1 : Ctrl := Create (Ident_Int (18));
                Obj2 : Ctrl := (Ada.Finalization.Controlled with
                                D => True,
                                Finalized => Ident_Bool (False),
                                C2 => 2.0 * Float (Ident_Int (19)));
                Obj3 : constant Ctrl := (Ada.Finalization.Controlled with
                                         D => False,
                                         Finalized => Ident_Bool (False),
                                         C1 => Ident_Int (20));
                             -- Finalization: Tasking_Error
            begin
                Comment ("Finalization because of return statement");

                Use_It (Obj1); -- Prevent optimization of Objects.
                Use_It (Obj2); -- (Critical if AI-147 is adopted.)
                Use_It (Obj3);

                if not Ident_Bool (Obj3.D) then
                   return;
                end if;

                Failed ("Return not taken");
            end Do_Something;
        begin
            Do_Something;
            Failed ("No exception raised by finalization on return statement");
        exception
            when Program_Error =>
                if not Was_Finalized (Ident_Int (18)) or
                   not Was_Finalized (Ident_Int (19)) then
                    Failed ("Missing finalizations - 5");
                end if;
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Message (E) & " - 5");
        end A_Return;

    Except: -- Case 6
        declare
            Funky_Error : exception;

            procedure Do_Something is
                Obj1 : Ctrl :=
                    (Ada.Finalization.Controlled with
                     D => True,
                     Finalized => Ident_Bool (False),
                     C2 => 2.0 * Float (
                           Ident_Int(23))); -- Finalization: User_Error
                Obj2 : Ctrl := Create (Ident_Int (24));
                Obj3 : Ctrl := Create (Ident_Int (25));
                Obj4 : constant Ctrl := (Ada.Finalization.Controlled with
                                         D => False,
                                         Finalized => Ident_Bool (False),
                                         C1 => Ident_Int (26));
            begin
                Comment ("Finalization because of exception propagation");

                Use_It (Obj1); -- Prevent optimization of Objects.
                Use_It (Obj2); -- (Critical if AI-147 is adopted.)
                Use_It (Obj3);
                Use_It (Obj4);

                if not Ident_Bool (Obj4.D) then
                   raise Funky_Error;
                end if;

                Failed ("Exception not raised");
            end Do_Something;
        begin
            Do_Something;
            Failed ("No exception raised by finalization on exception " &
                    "propagation");
        exception
            when Program_Error =>
                if not Was_Finalized (Ident_Int (24)) or
                   not Was_Finalized (Ident_Int (25)) or
                   not Was_Finalized (Ident_Int (26)) then
                    Failed ("Missing finalizations - 6");
                end if;
            when Funky_Error =>
                Failed ("Wrong exception propagated");
                    -- Should be Program_Error (7.6.1(19)).
            when E: others =>
                Failed ("Exception " & Exception_Name (E) &
                        " raised - " & Exception_Message (E) & " - 6");
        end Except;

    Result;
end C761011;

