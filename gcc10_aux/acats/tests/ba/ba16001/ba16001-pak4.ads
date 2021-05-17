

limited with BA16001.Pak3;            -- OK.
limited with BA16001_Func;            -- ERROR: Not package
limited with BA16001_Genpak;          -- ERROR: Not package
limited with BA16001.Gensub;          -- ERROR: Not package
limited with BA16001.Instpak;         -- ERROR: Not package
limited private with BA16001.Instsub; -- ERROR: Not package
limited private with BA16001.Proc;    -- ERROR: Not package
limited private with BA16001.Renfunc; -- ERROR: Not package
limited with BA16001.Rengenpak;       -- ERROR: Not package
limited with BA16001.Rengensub;       -- ERROR: Not package
limited with BA16001.Reninstpak;      -- ERROR: Not package
limited with BA16001.Reninstsub;      -- ERROR: Not package
limited with BA16001_Renpak3;         -- ERROR: Not package
limited with BA16001_Renproc;         -- ERROR: Not package
limited with BA16001.Pak2.Nested;     -- ERROR: Nested package
limited with BA16001.Pak2.Inner_Proc; -- ERROR: Nested and not package
limited private with BA16001.Pak2.Math;--ERROR: Nested package
limited with Pak3;                    -- ERROR: Not root package
limited private with Pak31;           -- ERROR: Not root package
limited with Pak3.Pak31;              -- ERROR: Not root package
package BA16001.Pak4 is
   type Wowser is (Red, Blue, Green);
end BA16001.Pak4;
