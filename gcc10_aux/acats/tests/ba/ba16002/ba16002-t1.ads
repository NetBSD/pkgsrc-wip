
with BA16002.Pak2.Nested;        -- ERROR: Nested package
with BA16002.Pak2.Inner_Proc;    -- ERROR: Nested procedure
private with BA16002.Pak2.Math;  -- ERROR: Nested package
private with BA16002.Pak2.Inner_Func;-- ERROR: Nested function
private with Pak3;               -- ERROR: Not root package
private with Pak31;              -- ERROR: Not root package
private with Pak3.Pak31;         -- ERROR: Not root package
package BA16002.T1 is
   type Wowser is (Red, Blue, Green);
end BA16002.T1;
