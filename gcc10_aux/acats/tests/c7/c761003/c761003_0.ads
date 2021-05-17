
------------------------------------------------------------------ C761003_0

with Ada.Finalization;
package C761003_0 is

  type Global(Tag: Character) is new Ada.Finalization.Controlled
    with null record;

  procedure Initialize( It: in out Global );
  procedure Finalize  ( It: in out Global );

  Null_Global : Global('1') := (Ada.Finalization.Controlled with Tag => '1');

  type Second(Tag: Character) is new Ada.Finalization.Limited_Controlled
    with null record;

  procedure Initialize( It: in out Second );
  procedure Finalize  ( It: in out Second );

end C761003_0;
