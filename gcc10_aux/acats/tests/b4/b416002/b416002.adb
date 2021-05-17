
with B416002_A; use B416002_A;
procedure B416002 is

   Maze : Window;

   procedure Limit (X : in out Natural) is
   begin
      if X > 20 then
         X := 20;
      end if;
   end Limit;

   procedure Sink (X : in Natural) is null;

begin

   -- Create sprites:
   Create_Sprite (Maze, "User  ", X=> 10, Y => 10, K => Player, C => Yellow);

   Create_Sprite (Maze, "Blinky", X=> 1, Y => 1, K => Ghost, C => Red);

   Create_Sprite (Maze, "Pinky ", X=> 1, Y => 20, K => Ghost, C => Pink);

   Create_Sprite (Maze, "Inky  ", X=> 20, Y => 20, K => Ghost, C => Cyan);

   Create_Sprite (Maze, "Clyde ", X=> 20, Y => 1, K => Ghost, C => Orange);

   -- Try a variety of variable and constant contexts:

   if Maze("Blinky").C /= Red then                          -- OK.
      null;
   end if;

   Maze("User  ").K := Ghost;                               -- ERROR:

   Limit (Maze("Clyde ").X);                                -- ERROR:

   Sink (Maze("Clyde ").Y);                                 -- OK.

   declare
      S1 : Sprite renames Maze("Clyde ");                   -- OK.
         -- This is a variable context, but it is OK to rename a
         -- constant. S1 therefore is a constant.
   begin
      Maze("Blinky") := S1;                                 -- ERROR:

      S1.C := White;                                        -- ERROR:
   end;

   case Maze("Pinky ").K is                                 -- OK.
      when Ghost => null;
      when others => raise Program_Error;
   end case;

end B416002;

