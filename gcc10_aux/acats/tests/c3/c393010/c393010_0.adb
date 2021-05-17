
with TCTouch;
package body C393010_0 is

  procedure Print( T: Ticket ) is
  begin
    -- Check that a call on an abstract operation is a dispatching operation
    Label( Ticket'Class( T ) );
    -- Appropriate_IO.Put( T.Flight & T.Serial_Number );
    TCTouch.Touch('P'); -------------------------------------------------- P
  end Print;

end C393010_0;
