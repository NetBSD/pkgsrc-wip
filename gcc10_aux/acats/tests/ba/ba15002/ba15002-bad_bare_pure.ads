
generic
    pragma Pure; -- ERROR:
        -- The pragma is not allowed here.
    type T is new Character;
package BA15002.Bad_Bare_Pure is
end BA15002.Bad_Bare_Pure;

