
package BA15002.Also_Bad_Elaborate_Body is
    pragma Preelaborate(BA15002.Also_Bad_Preelaborate.Nested); -- ERROR:
        -- The pragma must give the name of the enclosing unit if given first.
    package Nested is
       Subtype S is Integer range 1 .. 10;
    end Nested;
end BA15002.Also_Bad_Elaborate_Body;
