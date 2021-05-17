

     --==================================================================--


--
-- Public child unit:
--

with B840001_0.B840001_4;

package B840001_1.B840001 is

   use type B840001_0;                                                -- ERROR:
                              -- Name in use type clause must denote a subtype.

   use type B840001_0.B840001_4;                                      -- ERROR:
                              -- Name in use type clause must denote a subtype.

   use type B840001_0.B840001_4.Der_Tag;                              -- OK.

   TagObj : Integer := Tag_Op (B840001_0.B840001_4.DerObj);           -- ERROR:
                  -- Tag_Op is not directly visible (not a primitive operator).

   use type B840001_0.B840001_4.Another_Integer;                      -- OK.

   AnoObj01 : Another_Integer;                                        -- ERROR:
                            -- Name in use type clause is not directly visible.

   -- Implicitly declared primitive subprogram is not directly visible:
   AnoObj02 : B840001_0.B840001_4.Another_Integer := Int_Op;          -- ERROR:
                  -- Int_Op is not directly visible (not a primitive operator).


   -- A use type clause for My_Integer exists in the private part of this 
   -- unit's parent.
   Object01 : My_Integer;                                             -- ERROR:
                                         -- My_Integer is not directly visible.

   -- Explicitly declared primitive subprogram is not directly visible:
   Object02 : B840001_0.My_Integer := Int_Op;                         -- ERROR:
                  -- Int_Op is not directly visible (not a primitive operator).
  
   Object03 : B840001_0.My_Integer := -B840001_0.MyInt01;             -- ERROR:
              -- Unary "-" not directly visible (visible part of public child).

   Object04 : Boolean := 
              (B840001_0.MyInt02 >= B840001_0.MyInt01);               -- ERROR:
          -- Ordering ">=" not directly visible (visible part of public child).


private

   Object05 : B840001_0.My_Integer := Int_Op;                         -- ERROR:
                  -- Int_Op is not directly visible (not a primitive operator).
  
   Object06 : B840001_0.My_Integer :=
              B840001_0.MyInt01/B840001_0.MyInt01;                    -- OK.
                                                         -- "/" use-visible.
   Object07 : B840001_0.My_Integer := 
              B840001_0.MyInt02 rem B840001_0.MyInt01;                -- OK.
                                                       -- "rem" use-visible.
   Object08 : Boolean := 
    (B840001_0.B840001_4.Another01 <= B840001_0.B840001_4.Another02); -- OK.
                                                        -- "<=" use-visible.

   BadObj01 : B840001_0.Der_Integer := 
              B840001_0.DerInt01 - B840001_0.DerInt01;                -- ERROR:
                         -- "-" not directly visible (B840001_0.Der_Integer not
                         -- named in use type clause).

end B840001_1.B840001;
