
------------------------------------------------------------------- C761006_0

with Report;
with C761006_Support;
package body C761006_0 is

  package Sup renames C761006_Support;

  procedure Initialize( It: in out Good ) is
  begin
    Sup.Events_Occurring( Sup.Good_Initialize ) := True;
    It.Initialized := True;
  end Initialize;

  procedure Adjust    ( It: in out Good ) is
  begin
    Sup.Events_Occurring( Sup.Good_Adjust ) := True;
    It.Adjusted := True;
    It.Unique := C761006_Support.Unique_Value;
  end Adjust;

  procedure Finalize  ( It: in out Good ) is
  begin
    Sup.Events_Occurring( Sup.Good_Finalize ) := True;
  end Finalize;

  procedure Initialize( It: in out Bad_Initialize ) is
  begin
    Sup.Raise_Propagating_Exception(Report.Ident_Bool(True));
  end Initialize;

  procedure Adjust( It: in out Bad_Adjust ) is
  begin
    Sup.Raise_Propagating_Exception(Report.Ident_Bool(True));
  end Adjust;

  procedure Finalize( It: in out Bad_Finalize ) is
  begin
    Sup.Raise_Propagating_Exception(Report.Ident_Bool(True));
  end Finalize;

end C761006_0;
