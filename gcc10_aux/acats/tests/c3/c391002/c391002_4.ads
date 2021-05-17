
----------------------------------------------------------------- C391002_4

with C391002_3;
package C391002_4 is -- Communications
  package Modules renames C391002_3;

  type Public_Comm is new Modules.Electronics_Module with
    record
      TC_VC : Integer;
    end record;

  type Private_Comm is new Modules.Electronics_Module with private;

  type Mil_Comm is new Modules.Electronics_Module with private;

  procedure Creator( Plugs : in Modules.Electronics_Module;
                     Gives : out Mil_Comm);

  function  Creator( Key : Integer; Plugs : in Modules.Electronics_Module )
            return Private_Comm;

  procedure Setup( It : in out Public_Comm;  Value : in Integer );
  procedure Setup( It : in out Private_Comm; Value : in Integer );
  procedure Setup( It : in out Mil_Comm;     Value : in Integer );

  function  Selector( It : Public_Comm )  return Integer;
  function  Selector( It : Private_Comm ) return Integer;
  function  Selector( It : Mil_Comm )     return Integer;

private
  type Private_Comm is new Modules.Electronics_Module with
    record
      TC_PC : Integer;
    end record;

  type Mil_Comm is new Modules.Electronics_Module with 
    record
      TC_MC : Integer;
    end record;
end C391002_4; -- Communications
