
with Ada.Finalization;
generic
    pragma Preelaborate; -- ERROR:
        -- The pragma is not allowed here.
    type T is new Finalization.Limited_Controlled with private;
package BA15002.Bad_Bare_Preelaborate is
end BA15002.Bad_Bare_Preelaborate;

