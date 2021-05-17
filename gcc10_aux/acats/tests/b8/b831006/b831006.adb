

package body B831006 is

   protected body Prot1 is

      not overriding
      procedure Bump;                                 -- ERROR: {1:7;1}
         -- Note: Not a protected subprogram.

      not overriding
      procedure No_Op is null;                        -- ERROR: {1:7;1}

      not overriding
      procedure Add (Val : in Natural) is             -- ERROR: {1:7}
      begin
         Counter := Counter + Val;
      end Add;

      not overriding
      function Value return Natural is (Counter);     -- ERROR: {1:7;1}

      procedure Bump is                               -- OPTIONAL ERROR: {1:7}
         -- The specification of Bump is illegal.
      begin
         Counter := Counter + 1;
      end Bump;

      function Triple return Natural is (Counter*3);  -- OK. {7;1}

   end Prot1;


   protected body Prot2 is -- Type, tagged.

      not overriding
      procedure Bump;                                 -- ERROR: {1:7;1}
         -- Note: Not a protected subprogram.

      not overriding
      procedure Reset is null;                        -- ERROR: {1:7;1}

      not overriding
      function Double return Natural is (Counter*2);  -- ERROR: {1:7;1}

      overriding
      procedure Add (Val : in Natural) is             -- ERROR: {1:7}
      begin
         Counter := Counter + Val;
      end Add;

      overriding
      function Value return Natural is                -- ERROR: {1:7}
      begin
         return Counter;
      end Value;

      procedure Bump is                               -- OPTIONAL ERROR: {1:7}
         -- The specification of Bump is illegal.
      begin
         Counter := Counter + 1;
      end Bump;

      function Triple return Natural is (Counter*3);  -- OK. {7;1}

   end Prot2;

end B831006;
