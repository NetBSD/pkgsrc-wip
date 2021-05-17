 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with TCTouch;
package body C760012_0 is

  package body Firsts is

    procedure Initialize( T : in out Constrained_First ) is
    begin
      TCTouch.Touch('C');   ----------------------------------------------- C
    end Initialize;

    procedure Finalize  ( T : in out Constrained_First ) is
    begin
      TCTouch.Touch('S');   ----------------------------------------------- S
    end Finalize;

    procedure Initialize( T : in out Simple_First ) is
    begin
      T.My_Init_Seq_Number := 0;
      TCTouch.Touch('A');   ----------------------------------------------- A
    end Initialize;

    procedure Finalize  ( T : in out Simple_First ) is
    begin
      TCTouch.Touch('T');   ----------------------------------------------- T
    end Finalize;

  end Firsts;

  procedure Initialize( T : in out Constrained_Second ) is
  begin
    TCTouch.Touch('D');   ------------------------------------------------- D
  end Initialize;

  procedure Finalize  ( T : in out Constrained_Second ) is
  begin
    TCTouch.Touch('R');   ------------------------------------------------- R
  end Finalize;


  procedure Initialize( T : in out Simple_Second ) is
  begin
    T.My_Init_Seq_Number := 0;
    TCTouch.Touch('A');   ------------------------------------------------- A
  end Initialize;

  procedure Finalize  ( T : in out Simple_Second ) is
  begin
    TCTouch.Touch('T');   ------------------------------------------------- T
  end Finalize;

  procedure Initialize( L : in out List_Item ) is
  begin
    TCTouch.Touch('F');   ------------------------------------------------- F
  end Initialize;

  procedure Finalize  ( L : in out List_Item ) is
  begin
    TCTouch.Touch('Q');   ------------------------------------------------- Q
  end Finalize;

end C760012_0;
