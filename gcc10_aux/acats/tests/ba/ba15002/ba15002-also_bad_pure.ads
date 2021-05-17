
package BA15002.Also_Bad_Pure is
    pragma Pure(BA15002.Very_Bad_Pure.Nested); -- ERROR:
        -- The pragma must give the name of the enclosing unit.
    package Nested is
       Subtype S is Integer range 1 .. 10;
    end Nested;
end BA15002.Also_Bad_Pure;
