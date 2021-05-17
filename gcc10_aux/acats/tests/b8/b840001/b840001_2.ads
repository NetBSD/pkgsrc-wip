

     --==================================================================--


with B840001_0;
with B840001_1; use B840001_1;
package B840001_2 is

   -- Use of direct and expanded names in use type clauses (note that the
   -- second clause is unnecessary due to the earlier use-package clause):
   use type B840001_0.My_Integer;                                     -- OK.
   use type My_Tag;                                                   -- OK.

   TagEqual : Boolean := (Tag01 = Tag02);                             -- OK.
                                                         -- "=" use-visible.
   IntAdd   : B840001_0.My_Integer :=
              B840001_0.MyInt01 + B840001_0.MyInt02;                  -- OK.
                                                         -- "+" use-visible.
   IntMod   : B840001_0.My_Integer :=
              B840001_0.MyInt01 mod B840001_0.MyInt02;                -- OK.
                                                       -- "mod" use-visible.

   IntNeg   : B840001_0.My_Integer := - B840001_0.MyInt01;            -- OK.
                                                   -- unary "-" use-visible.

   IntLess  : Boolean := (B840001_0.MyInt01 < B840001_0.MyInt02);     -- OK.
                                                         -- "<" use-visible.

end B840001_2;
