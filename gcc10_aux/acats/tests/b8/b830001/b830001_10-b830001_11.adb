
-----------------------------------------------------------
with B830001_10.B830001_12;
separate (B830001_10)
procedure B830001_11 is                                               -- ERROR:
   I : Integer;                 -- Both child package B830001_10.B830001_12 and
begin                           -- variable B830001_10.B830001_12 are visible.
   I := I + 5;
end B830001_11;
