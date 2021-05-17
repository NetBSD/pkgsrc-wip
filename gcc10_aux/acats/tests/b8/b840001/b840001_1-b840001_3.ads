

     --==================================================================--

--
-- Private child unit:
--

with B840001_0;                    
private package B840001_1.B840001_3 is
  
   -- Scope of use type clause in private part of parent unit includes
   -- visible and private parts of private child unit:

   Squared : B840001_0.My_Integer := B840001_0.MyInt01**2;            -- OK.
                                                        -- "**" use-visible.
   Int_Mul : B840001_0.My_Integer := 
      B840001_0.MyInt02*B840001_0.MyInt01;                            -- OK.
                                                        --  "*" use-visible.

   IntNotEqual : Boolean := (B840001_0.MyInt01 /= B840001_0.MyInt02); -- OK.
                                                       --  "/=" use-visible.

private

   AbsValue : B840001_0.My_Integer := abs B840001_0.MyInt02;          -- OK.
                                                       -- "abs" use-visible.
   Int_Sub : B840001_0.My_Integer := 
      B840001_0.MyInt02-B840001_0.MyInt01;                            -- OK.
                                                  -- binary "-" use-visible.
   IntGreat : Boolean := (B840001_0.MyInt02 > B840001_0.MyInt01);     -- OK.
                                                         -- ">" use-visible.

end B840001_1.B840001_3;
