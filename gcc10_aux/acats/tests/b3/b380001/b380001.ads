
with B380001_0;
package B380001 is
  use B380001_0;

  type Illegal_Reuse( New_Disc : Boolean ) is
    new Root( New_Disc ) with record
      Component : String(1..10);                                  -- ERROR:
                                        -- component names must be distinct
    end record;

---------------------------------------------------------------------------

  type Illegal_Use_Of_Name is new Root
    with record
      Disc_Name : Character;                                      -- ERROR:
                          -- name of inherited discriminant may not be used
    end record;

---------------------------------------------------------------------------

  type Illegal_Enclosure;

  type Component( X: access Illegal_Enclosure ) is
    limited null record;

  type Illegal_Enclosure is limited record
    UFC: Component( B380001.Illegal_Enclosure'Access );           -- ERROR:
                                 -- attribute_reference must be direct_name
  end record;

---------------------------------------------------------------------------

  type Illegal_Enclosure_2;
  type Access_IE2 is access all Illegal_Enclosure_2;

  type Component_2( X: access Illegal_Enclosure_2 ) is
    limited null record;

  type Illegal_Enclosure_2 is limited record
    UFC: Component_2( Access_IE2'(Illegal_Enclosure_2'Access) );  -- ERROR:
                -- attribute_reference must be direct name and appear alone
  end record;

---------------------------------------------------------------------------

  type Illegal_Enclosure_3;

  type Component_3( X: access Illegal_Enclosure_3 ) is
    limited null record;

  type Illegal_Enclosure_3 is limited record
    UFC: Component_3( Illegal_Enclosure_3'Address );              -- ERROR:
                                 -- attribute_reference must be access type
  end record;

---------------------------------------------------------------------------

  type Illegal_Enclosure_4;

  type Component_4( X: access Illegal_Enclosure_4 ) is
    limited null record;

  type Illegal_Enclosure_4 is limited record
    UFC: Component_4( Component_4'Access );                       -- ERROR:
                                          -- attribute_reference wrong type
  end record;

---------------------------------------------------------------------------

  type Illegal_Enclosure_5;

  type Access_IE5 is access Illegal_Enclosure_5;

  function Fn(X: access Illegal_Enclosure_5)
    return Access_IE5;

  type Component_5( X: access Illegal_Enclosure_5 ) is
    limited null record;

  type Illegal_Enclosure_5 is limited record
    UFC: Component_5( Fn(Illegal_Enclosure_5'Access) );           -- ERROR:
                -- current instance attribute_reference must be direct name
  end record;

---------------------------------------------------------------------------

  type Illegal_Enclosure_6 is limited private;

  type Access_IE6 is access all Illegal_Enclosure_6;

  function Fx(X: access Illegal_Enclosure_6)
    return Illegal_Enclosure_6;

  type Component_6( X: access Illegal_Enclosure_6 ) is
    limited null record;

private


  type Illegal_Enclosure_6 is limited record
    UFC: Component_6( Fx(Illegal_Enclosure_6'Access)'Access );    -- ERROR:
                                                     -- must be direct_name
  end record;

--      Check that the name of a non-inherited discriminant is not
--      allowed within the discriminant part.

  type Rad_Branch( Disc_Name : Natural ) is                       -- OK
                  -- discriminant name not inherited in this derivation
    new Root( False ) with record
      Stuff : String(1..10);
    end record;

end B380001;
