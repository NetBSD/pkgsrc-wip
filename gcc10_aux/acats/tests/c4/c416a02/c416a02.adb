
with Report;
with F416A00.C416A02_A; use F416A00.C416A02_A;
with TcTouch;
procedure C416A02 is

    Maze : New_Window;

    use all type F416A00.Kind; -- Makes enumeration literals visible.
    use all type F416A00.Color; -- Makes enumeration literals visible.

begin

    Report.Test ("C416A02",
                 "Check that the overloaded routines can be added to an " &
                 "inherited indexing aspect and the new routines can be " &
                 "used in a generalized indexing");

    -- Create sprites:
    Create_Sprite (Maze, "User  ", X=> 10, Y => 10, K => Player, C => Yellow);

    Create_Sprite (Maze, "Blinky", X=> 1, Y => 1, K => Ghost, C => Red);

    Create_Sprite (Maze, "Pinky ", X=> 1, Y => 20, K => Ghost, C => Pink);

    Create_Sprite (Maze, "Inky  ", X=> 20, Y => 20, K => Ghost, C => Cyan);

    Create_Sprite (Maze, "Clyde ", X=> 20, Y => 1, K => Ghost, C => Orange);

    -- Check some sprite properties by name: (overridden/overloaded CRef(Name))
    if Maze("Blinky").C /= Red then               ------- bB
       Report.Failed ("Wrong color (A)");
    end if;
    if Maze("Clyde ") /= Ghost then               ------- aC
       Report.Failed ("Wrong kind (A1)");
    end if;
    if Maze("User  ") /= Player then              ------- aU
       Report.Failed ("Wrong kind (A2)");
    end if;
    begin
       if Maze("Stinky") /= Ghost then            ------- aS
          Report.Comment ("Weird");
       end if;
       Report.Failed ("Exception not raised by unknown name (A)");
    exception
       when Missing_Error => null; -- Expected.
    end;

    TcTouch.Validate (Expected => "bBaCaUaS",
                      Message => "Index by name wrong (A)");

    -- Check some sprite properties by position: (inherited CRef(X, Y))
    if Maze(10, 10).C /= Yellow then             ------- dJJ
       Report.Failed ("Wrong color (B)");
    end if;
    if Maze(20, 20).K /= Ghost then              ------- dTT
       Report.Failed ("Wrong kind (B)");
    end if;

    TcTouch.Validate (Expected => "dJJdTT",
                      Message => "Index by position wrong (B)");

    -- Change sprite color/kind by name: (overridden/overloaded VRef(Name))
    Maze("Clyde ").C := White;                  ------- tC
    Maze("Clyde ") := Power_Pill;               ------- sC

    if Maze("User  ") /= Player or else         ------- aU
       Maze("User  ").C /= Yellow then          ------- bU
       Report.Failed ("Change by name changed wrong item (C)");
    end if;

    if Maze("Clyde ") /= Power_Pill or else     ------- aC
       Maze("Clyde ").C /= White or else        ------- bC
       Maze("Clyde ").X /= 20 or else           ------- bC
       Maze("Clyde ").Y /= 1 then               ------- bC
       Report.Failed ("Change by name failed (C)");
    end if;

    TcTouch.Validate (Expected => "tCsCaUbUaCbCbCbC",
                      Message => "Modifications wrong (C)");

    Report.Result;

end C416A02;
