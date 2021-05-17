
package BA15002.Very_Bad_Pure is
    type T is new Integer;
    procedure P;
    pragma Pure; -- ERROR:
	-- The pragma must be first (or give a name of a nested item).
end BA15002.Very_Bad_Pure;
