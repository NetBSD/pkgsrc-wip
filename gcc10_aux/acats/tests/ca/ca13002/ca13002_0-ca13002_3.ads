
     --==================================================================--

-- Third child.
package CA13002_0.CA13002_3 is           -- Terminal_Driver.DOS_ANSI

   procedure Move_Cursor (Col : in TC_Call_From);

   procedure CA13002_5;                  -- Terminal_Driver.DOS_ANSI.Cursor_Up
                                         -- implementation will be as a 
                                         -- separate subunit.
end CA13002_0.CA13002_3;
