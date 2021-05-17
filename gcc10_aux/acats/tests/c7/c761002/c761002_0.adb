
with Report;
with TCTouch;
package body C761002_0 is

  procedure Finalize( It: in out Global ) is
  begin
    TCTouch.Touch('F');  ------------------------------------------------- F
  end Finalize;

  procedure Finalize( It: in out Second ) is
  begin
    TCTouch.Touch('S');  ------------------------------------------------- S
  end Finalize;
end C761002_0;
