
-----------------------------------------------------------------------------
with Report;        
with TCTouch;
with C761005_Support;
package body C761005_1 is

  package Sup renames C761005_Support;

  procedure Initialize( It: in out Final_Abstract ) is
  begin
    Sup.Inits_Called := Sup.Inits_Called +1;
    It.Tag := Sup.Pick_Char;
    Sup.Inits_Order(Sup.Inits_Called) := It.Tag;
  end Initialize;
  
  procedure Finalize( It: in out Final_Abstract ) is
  begin
    TCTouch.Touch(It.Tag);
  end Finalize;

  procedure Initialize( It: in out Ltd_Final_Abstract_Child ) is
  begin
    Sup.Inits_Called := Sup.Inits_Called +1;
    It.Tag := Sup.Pick_Char;
    Sup.Inits_Order(Sup.Inits_Called) := It.Tag;
  end Initialize;
  
  procedure Finalize( It: in out Ltd_Final_Abstract_Child ) is
  begin
    TCTouch.Touch(It.Tag);
  end Finalize;
end C761005_1;
