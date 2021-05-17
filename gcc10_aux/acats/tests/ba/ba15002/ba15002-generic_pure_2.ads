    -- The pragma must have a name.

with BA15002.OK_Pure;
package BA15002.Generic_Pure_2 is new BA15002.OK_Pure (Boolean);
pragma Pure(BA15002.Generic_Pure); -- ERROR:
    -- The pragma must have the name of the preceding unit.

