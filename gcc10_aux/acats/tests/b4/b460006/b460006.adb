
package body B460006 is

    package body P is
        Obj_Copy : Q.NT (4) := Q.NT (Obj); -- OK: A view conversion is not
                                           -- required here, and 4.6(21-23)
                                           -- does not apply.

        C_Copy : Character := T (Q.X).C (2); -- OK: A view conversion is not
                                             -- required here.

        C_Ren : Character renames T (Q.X).C (2); -- ERROR: Q.NT is not tagged.

        Obj_Ren : Q.NT renames Q.NT (Obj); -- ERROR: Q.NT is not tagged.
    begin
        Q.X := Q.Y;
        --Obj_Ren := Q.Y;
    end P;

begin
    declare
        P_Obj1, P_Obj2 : P.T(5);
        Q_Obj : Q.Nt(5);
    begin
        Q_Obj  := Q.Nt(P_Obj1); -- OK: Both types are untagged.
        P_Obj2 := P.T (Q_Obj);  -- OK: Both types are untagged.
    end;
end B460006;

