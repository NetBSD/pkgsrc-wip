
------------------------------------------------------------------ C761003_1

with Ada.Finalization;
package C761003_1 is

  type Global is abstract new Ada.Finalization.Controlled with record
    Tag: Character;
  end record;

  procedure Initialize( It: in out Global );
  procedure Finalize  ( It: in out Global );

  type Second is abstract new Ada.Finalization.Limited_Controlled with record
    Tag: Character;
  end record;

  procedure Initialize( It: in out Second );
  procedure Finalize  ( It: in out Second );

end C761003_1;
