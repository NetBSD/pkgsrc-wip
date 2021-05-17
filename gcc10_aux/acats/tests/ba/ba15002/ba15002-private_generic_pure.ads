
generic
package BA15002.Private_Generic_Pure is
    -- Nothing visible!
private
    pragma Pure; -- ERROR:
        -- The pragma is not allowed here.
end BA15002.Private_Generic_Pure;
