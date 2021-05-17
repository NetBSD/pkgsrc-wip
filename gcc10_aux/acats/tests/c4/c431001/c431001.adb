

with C431001_0;
with Report;
procedure C431001 is

   -- Tagged type
   -- Named component associations
   DAT : C431001_0.Recording :=
      (Artist     => "Aerosmith           ",
       Category   => C431001_0.Rock,
       Length     => 48.5,
       Selections => 10);

   -- Type extensions
   -- Named component associations
   Disc1 : C431001_0.CD :=
      (Artist     => "London Symphony     ",
       Category   => C431001_0.Classical,
       Length     => 55.0,
       Selections => 4,
       Recorded   => C431001_0.Digital,
       Mastered   => C431001_0.Digital);
   
   -- Named component associations with others
   Disc2 : C431001_0.CD :=
      (Artist     => "Pink Floyd          ",
       Category   => C431001_0.Rock,
       Length     => 51.8,
       Selections => 5,
       others     => C431001_0.Audio); -- Recorded
                                       -- Mastered
   
   -- Positional component associations
   Album1 : C431001_0.Vinyl :=
      ("Hammer              ", -- Artist
       C431001_0.Rap,          -- Category
       46.2,                   -- Length
       9,                      -- Selections
       C431001_0.LP_33);       -- Speed
   
   -- Mixed positional and named component associations
   -- Named component associations out of order
   Album2 : C431001_0.Vinyl :=
      ("Balinese Gamelan    ", -- Artist 
       C431001_0.World,        -- Category
       42.6,                   -- Length
       14,                     -- Selections
       C431001_0.LP_33);       -- Speed
   
   -- Type extension, parent is also type extension
   -- Named notation, components out of order
   Data : C431001_0.CD_ROM :=
      (Storage    => 140,
       Mastered   => C431001_0.Digital,
       Category   => C431001_0.Rock,
       Selections => 10,
       Recorded   => C431001_0.Digital,
       Artist     => "Black, Clint        ",
       Length     => 48.5);

   -- Null tagged type
   Null_Rec : C431001_0.Null_Tagged := (null record);

   -- Null type extension
   Null_Ext : C431001_0.Null_Extension := (null record);

   -- Nonnull extension of null parent
   Ext_Of_Null : C431001_0.Extension_Of_Null := (True, 0);

   -- Null extension of nonnull parent
   Null_Ext_Of_Nonnull : C431001_0.Null_Extension_Of_Nonnull
      := (False, 1);

begin

   Report.Test ("C431001", "Aggregate values for type extensions");

   C431001_0.Print (C431001_0.Catalog_Entry (DAT, C431001_0.TC_Recording));
   C431001_0.Print (C431001_0.Catalog_Entry (Disc1, C431001_0.TC_CD));
   C431001_0.Print (C431001_0.Catalog_Entry (Disc2, C431001_0.TC_CD));
   C431001_0.Print (C431001_0.Catalog_Entry (Album1, C431001_0.TC_Vinyl));
   C431001_0.Print (C431001_0.Catalog_Entry (Album2, C431001_0.TC_Vinyl));
   C431001_0.Print (C431001_0.Catalog_Entry (Data, C431001_0.TC_CD_ROM));

   C431001_0.TC_Dispatch (Null_Rec, C431001_0.TC_Null_Tagged);
   C431001_0.TC_Dispatch (Null_Ext, C431001_0.TC_Null_Extension);
   C431001_0.TC_Dispatch (Ext_Of_Null, C431001_0.TC_Extension_Of_Null);
   C431001_0.TC_Dispatch
      (Null_Ext_Of_Nonnull, C431001_0.TC_Null_Extension_Of_Nonnull);

   -- Tagged type
   -- Named component associations
   C431001_0.Print (C431001_0.Catalog_Entry
      (TC_Type => C431001_0.TC_Recording,
       R => C431001_0.Recording'(Artist     => "Zappa, Frank        ",
                                 Category   => C431001_0.Rock,
                                 Length     => 70.0,
                                 Selections => 38)));

   -- Type extensions
   -- Named component associations
   C431001_0.Print (C431001_0.Catalog_Entry
      (TC_Type => C431001_0.TC_CD,
       R => C431001_0.CD'(Artist     => "Dog, Snoop Doggy    ",
                          Category   => C431001_0.Rap,
                          Length     => 37.3,
                          Selections => 8,
                          Recorded   => C431001_0.Audio,
                          Mastered   => C431001_0.Digital)));

   -- Named component associations with others
   C431001_0.Print (C431001_0.Catalog_Entry
      (TC_Type => C431001_0.TC_CD,
       R => C431001_0.CD'(Artist     => "Judd, Winona        ",
                          Category   => C431001_0.Country,
                          Length     => 51.2,
                          Selections => 11,
                          others     => C431001_0.Digital))); -- Recorded
                                                              -- Mastered

   -- Positional component associations
   C431001_0.Print (C431001_0.Catalog_Entry
      (TC_Type => C431001_0.TC_Vinyl,
       R => C431001_0.Vinyl'("Davis, Miles        ",  -- Artist
                              C431001_0.Jazz,         -- Category
                              50.4,                   -- Length
                              10,                     -- Selections
                              C431001_0.LP_33)));      -- Speed

   -- Mixed positional and named component associations
   -- Named component associations out of order
   C431001_0.Print (C431001_0.Catalog_Entry
      (TC_Type => C431001_0.TC_Vinyl,
       R => C431001_0.Vinyl'("Zamfir              ",    -- Artist
                              C431001_0.World,          -- Category
                              Speed => C431001_0.LP_33,
                              Selections => 14,
                              Length => 56.5)));

   -- Type extension, parent is also type extension
   -- Named notation, components out of order
   C431001_0.Print (C431001_0.Catalog_Entry
      (TC_Type => C431001_0.TC_CD_ROM,
       R => C431001_0.CD_ROM'(Storage         => 720,
                              Category        => C431001_0.Classical,
                              Recorded        => C431001_0.Digital,
                              Artist          => "Baltimore Symphony  ",
                              Length          => 68.9,
                              Mastered        => C431001_0.Digital,
                              Selections      => 5)));
   
   -- Null tagged type
   C431001_0.TC_Dispatch
      (TC_Type => C431001_0.TC_Null_Tagged,
       N => C431001_0.Null_Tagged'(null record));

   -- Null type extension
   C431001_0.TC_Dispatch
      (TC_Type => C431001_0.TC_Null_Extension,
       N => C431001_0.Null_Extension'(null record));

   -- Nonnull extension of null parent
   C431001_0.TC_Dispatch
      (TC_Type => C431001_0.TC_Extension_Of_Null,
       N => C431001_0.Extension_Of_Null'(True, 3));

   -- Null extension of nonnull parent
   C431001_0.TC_Dispatch
      (TC_Type => C431001_0.TC_Extension_Of_Null,
       N => C431001_0.Extension_Of_Null'(False, 4));

   Report.Result;

end C431001;
