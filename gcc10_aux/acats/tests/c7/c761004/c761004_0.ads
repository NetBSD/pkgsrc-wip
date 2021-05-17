
----------------------------------------------------------------- C761004_0

with Ada.Finalization;
package C761004_0 is
  type Global is new Ada.Finalization.Controlled with record
    Tag : Character;
  end record;
  procedure Initialize( It: in out Global );
  procedure Finalize  ( It: in out Global );

  type Second is new Ada.Finalization.Limited_Controlled with record
    Tag : Character;
  end record;
  procedure Initialize( It: in out Second );
  procedure Finalize  ( It: in out Second );

end C761004_0;
