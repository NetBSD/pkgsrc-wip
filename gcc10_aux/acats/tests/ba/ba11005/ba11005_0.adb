
     --=================================================================--

with BA11005_0.BA11005_1;     -- Public child procedure.

with BA11005_0.BA11005_2;     -- Public child function.

with BA11005_0.BA11005_3;     -- Public child package.

package body BA11005_0 is

  BA11005_5 : Natural;                                      -- OK
                          -- library unit BA11005_5 not visible here

   -- When a parent body "with"s its own children, the simple names
   -- of the children (BA11005_1, BA11005_2, and BA11005_3) are
   -- directly visible.

   procedure BA11005_1 (I : in Int; R : out Int) is         -- ERROR:
   begin                                        -- Illegal homograph
      R := I - 2;
      -- Real body of procedure goes here.
   end BA11005_1;

   procedure BA11005_1 (X : out Int; Y : in Int) is         -- ERROR:
   begin                                        -- Illegal homograph
      X := Y * 5;
      -- Real body of procedure goes here.
   end BA11005_1;

   function BA11005_2 (I : Int) return Int is               -- ERROR:
   begin                                        -- Illegal homograph
      -- Real body of function goes here.
      return (I * 2);
   end BA11005_2;

   procedure BA11005_3 (I : in out Int) is                  -- ERROR:
   begin                                      -- Illegal overloading
      I := I + 5;
      -- Real body of procedure goes here.
   end BA11005_3;

   function BA11005_3 return Int is                         -- ERROR:
      I : Int := 44;                          -- Illegal overloading
   begin
      -- Real body of function goes here.
      return (I / 11);
   end BA11005_3;

   procedure BA11005_3 is                                   -- ERROR:
      I : Int := 24;                            -- Illegal homograph
   begin
      I := I / 4;
      -- Real body of procedure goes here.
   end BA11005_3;
   
  procedure BA11005_4 is                                   -- OK
      I : Int := 24;      -- library unit BA11005_4 not visible here
   begin
      I := I / 4;
      -- Real body of procedure goes here.
   end BA11005_4;

  procedure BA11005_6 is                                   -- OK
      I : Int := 24;      -- here to require the package body
   begin
      I := I / 4;
      -- Real body of procedure goes here.
   end BA11005_6;

end BA11005_0;
