
----------------------------------------------------------------- C392011_2

with C392011_1;
package C392011_2 is

  type Level_2 is new C392011_1.Level_1 with record
    Another_Int_Item : Integer;
  end record;
  
  -- note that Create becomes abstract upon this derivation hence:

  function Create return Level_2;

  procedure Check( Left, Right: in Level_2 );

end C392011_2;
