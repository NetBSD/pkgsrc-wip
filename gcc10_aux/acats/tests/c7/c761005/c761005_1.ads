
-----------------------------------------------------------------------------
with Ada.Finalization;
package C761005_1 is
  type Final_Abstract is abstract tagged private;

  type Ltd_Final_Abstract_Child is abstract tagged limited private;
  
  Inits_Order  : String(1..255);
  Inits_Called : Natural := 0;

private
  type Final_Abstract is abstract new Ada.Finalization.Controlled with record
    Tag: Character;
  end record;
  procedure Initialize( It: in out Final_Abstract );
  procedure Finalize  ( It: in out Final_Abstract );

  type Ltd_Final_Abstract_Child is
       abstract new Ada.Finalization.Limited_Controlled with record
    Tag: Character;
  end record;
  procedure Initialize( It: in out Ltd_Final_Abstract_Child );
  procedure Finalize  ( It: in out Ltd_Final_Abstract_Child );

end C761005_1;
