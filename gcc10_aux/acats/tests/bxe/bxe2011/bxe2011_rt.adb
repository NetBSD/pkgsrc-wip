

package body BXE2011_RT is
  procedure None is begin null; end;
  procedure One (P : Integer) is begin null; end;

  procedure TT_Proc (TT : access Tagged_Type) is
  begin
    TT.B_Field := True;
  end TT_Proc;
end BXE2011_RT;
