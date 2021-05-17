
---------------------------------------------------------------- BXC6001_0

package BXC6001_0 is

  type Array_Type is array(Positive range 1..2) of Character;

  type Root_Tagged is tagged record
    Inheritable_Component : Array_Type;
  end record;

end BXC6001_0;
