
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with TCTouch;
package body C391002_4 is -- Communications

  procedure Creator( Plugs : in Modules.Electronics_Module;
                     Gives : out Mil_Comm) is
  begin
    Gives := ( Plugs with TC_MC => -1 );
  end Creator;

  function  Creator( Key : Integer; Plugs : in Modules.Electronics_Module )
            return Private_Comm is
  begin
    return ( Plugs with TC_PC => Key );
  end Creator;

  procedure Setup( It : in out Public_Comm; Value : in Integer ) is
  begin
    It.TC_VC := Value;
    TCTouch.Assert( Value = 1, "Public_Comm");
  end Setup;

  procedure Setup( It : in out Private_Comm; Value : in Integer ) is
  begin
    It.TC_PC := Value;
    TCTouch.Assert( Value = 2, "Private_Comm");
  end Setup;

  procedure Setup( It : in out Mil_Comm; Value : in Integer ) is
  begin
    It.TC_MC := Value;
    TCTouch.Assert( Value = 3, "Private_Comm");
  end Setup;

  function  Selector( It : Public_Comm )  return Integer is
  begin
    return It.TC_VC;
  end Selector;

  function  Selector( It : Private_Comm ) return Integer is
  begin
    return It.TC_PC;
  end Selector;

  function  Selector( It : Mil_Comm )     return Integer is
  begin
    return It.TC_MC;
  end Selector;

end C391002_4; -- Communications
