
----------------------------------------------------------------- C392011_1

with C392011_0;
package C392011_1 is

  type Level_1 is new C392011_0.Level_0 with record
    Int_Item : Integer;
  end record;
  
  -- note that Create becomes abstract upon this derivation hence:

  function Create return Level_1;

  procedure Check( Left, Right: in Level_1 );

end C392011_1;
