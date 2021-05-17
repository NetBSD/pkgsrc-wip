    -- The pragma must have a name.

with BA15002.OK_Preelaborate;
package BA15002.Generic_Preelaborate_2 is new BA15002.OK_Preelaborate (Boolean);
pragma Preelaborate(BA15002.Generic_Preelaborate); -- ERROR:
    -- The pragma must have the name of the preceding unit.

