
generic
package BA15002.Private_Generic_Preelaborate is
    -- Nothing visible!
private
    pragma Preelaborate; -- ERROR:
        -- The pragma is not allowed here.
end BA15002.Private_Generic_Preelaborate;
