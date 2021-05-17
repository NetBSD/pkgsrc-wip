
-----------------------------------------------------------------------------
with Ada.Finalization;
package C761005_0 is
  type Final_Root(Tag: Character) is private;

  type Ltd_Final_Root(Tag: Character) is limited private; 
  
  Inits_Order  : String(1..255);
  Inits_Called : Natural := 0;
private
  type Final_Root(Tag: Character) is new Ada.Finalization.Controlled 
    with null record;
  procedure Initialize( It: in out Final_Root );
  procedure Finalize  ( It: in out Final_Root );
  
  type Ltd_Final_Root(Tag: Character) is new
Ada.Finalization.Limited_Controlled 
    with null record;
  procedure Initialize( It: in out Ltd_Final_Root );
  procedure Finalize  ( It: in out Ltd_Final_Root );
end C761005_0;
