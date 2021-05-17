
package body BA15002.Body_Pragmas is

    -- These pragmas are not allowed to apply to a package body:

    pragma Elaborate_Body; -- ERROR:
    pragma Preelaborate; -- ERROR:
    pragma Pure; -- ERROR:

    pragma Elaborate_Body(BA15002.Body_Pragmas); -- ERROR:
    pragma Preelaborate(BA15002.Body_Pragmas); -- ERROR:
    pragma Pure(BA15002.Body_Pragmas); -- ERROR:

    procedure Dummy is
    begin
        null;
    end Dummy;

end BA15002.Body_Pragmas;
