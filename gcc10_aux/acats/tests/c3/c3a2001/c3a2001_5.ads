
----------------------------------------------------------------------------

with C3A2001_1;
package C3A2001_5 is

  type Component is access C3A2001_1.Breaker'Class;

  type Circuit;
  type Connection is access Circuit;

  type Circuit is record
    The_Gadget : Component;
    Next : Connection;
  end record;

  procedure Flipper( The_Circuit : Connection );
  procedure Tripper( The_Circuit : Connection );
  procedure Restore( The_Circuit : Connection );
  procedure Failure( The_Circuit : Connection );

  Short : Connection := null;

end C3A2001_5;
