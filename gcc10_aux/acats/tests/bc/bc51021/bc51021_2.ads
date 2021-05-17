

     --==================================================================--


package BC51021_2 is

   type Unsigned_10 is mod 2 ** 10;

   type Fixed is delta 0.1 range -10.0 .. +10.0;

   type Untagged_Record is null record;

   type Tagged_Record is tagged null record;

   type Arr_Integer is array (1 .. 10) of Integer;

end BC51021_2;

