
with B831006A;
package B831006 is

   protected Prot1 is -- Single, untagged.

      not overriding
      procedure Add (Val : in Natural);               -- OK. {1:7;1}

      not overriding
      function Value return Natural;                  -- OK. {1:7;1}

   private
      Counter : Natural := 0;
   end Prot1;


   protected type Prot2 is new B831006A.Intf with -- Type, tagged.

      overriding
      procedure Add (Val : in Natural);               -- OK. {1:7;1}

      not overriding
      procedure Reset;                                -- OK. {1:7;1}

      overriding
      function Value return Natural;                  -- OK. {1:7;1}

   private
      Counter : Natural := 0;
   end Prot2;

end B831006;
