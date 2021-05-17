
     --==================================================================--

with Ada.Tags; 
use  Ada.Tags;
with B430001_0;
use  B430001_0;

procedure B430001 is

   A  :  Tag_Type;

   B  :  NNewTag_W_Null;

   BClass :  Tag_Type'Class := B;

   C  :  NewTag_Type;  

   Y1 :  Tag_Null := (null record);                                   -- OK.

   Y2 :  Tag_Type := (null record);                                   -- ERROR:
                                                      -- Components are needed.

   Y3 :  NewTag_W_Null := (Int1 => 0, Int2 => 0);                     -- OK.

   Y4 :  NewTag_W_Null 
      := (Tag_Type with null record);                                 -- OK.

   Y5 :  NewTag_W_Null := (A with null record);                       -- OK.

   Y6 :  NewTag_W_Null := A;                                          -- ERROR:
                                                             -- No null record.
   Y7 :  NewTag_W_Null 
      := (Tag_Type(B) with null record);                              -- OK.

   Y9 :  NewTag_Type                                  
      := (Tag_Type(B) with null record);                              -- ERROR:
                                                      -- Components are needed.
   Y10 :  NewTag_Type                                  
       := (Tag_Type(BClass));                                         -- ERROR:
                                                      -- Components are needed.

   --------------------------------------------------

   X1  : Tag_Type'Class := (5, 25);                                   -- ERROR:
                                  -- Aggregate may not be of a class-wide type.

   X2  : Tag_Type'Class := A;

   Ren : Tag_Type'Class renames Tag_Type'Class(A);

   subtype STag_Type is Tag_Type'Class;

   X3  : STag_Type := (33, 66);                                       -- ERROR:
                                  -- Aggregate may not be of a class-wide type.

   --------------------------------------------------
   procedure Proc (X : in out Tag_Type'Class) is
   begin
      if X'Tag = Tag_Type'Tag then
         X := (Int1 => 14, Int2 => -6);                               -- ERROR:
                                  -- Aggregate may not be of a class-wide type.
      end if;                     
   end Proc;

begin

   X2 := Tag_Type'Class'(Int1 => 10, Int2 => 20);                     -- ERROR:
                                  -- Aggregate may not be of a class-wide type.

   if X2 /= (Int1 => 0, Int2 => 10) then                              -- ERROR:
                                  -- Aggregate may not be of a class-wide type.
      null;                      
   end if;

   Op (STag_Type'(Int1 => 0, Int2 => 0));                             -- ERROR:
                                  -- Aggregate may not be of a class-wide type.

end B430001;
