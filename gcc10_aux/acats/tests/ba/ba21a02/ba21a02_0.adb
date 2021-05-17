

     --===================================================================--


package body BA21A02_0 is

   procedure Dummy is
   begin
      null;
   end Dummy;


   Five  : FA21A00.My_Int := FA21A00.Three + 2;                       -- OK.
                       -- Call to static function (predefined operator) (l).

   Stat  : Boolean := (FA21A00.Three = 3);                            -- OK.
                       -- Name of an object that is a static expression (n).

   Acc2  : FA21A00.AccTag := FA21A00.Tag1'Unchecked_Access;           -- OK.
                             -- Name of an object, but not as a primary (p).

   PrObj : Private_Type;                                              -- OK.
                             -- Default-initialized object of a private type
                             -- (within scope of full view) (q).

   PEObj : Private_Extension;                                         -- OK.
                        -- Default-initialized object of a private extension
                        -- (within scope of full view) (q).

   PrXAgg: Deriv_Priv := (Private_Type with "Hello");                 -- OK.
                           -- Extension aggregate with ancestor subtype of a
                           -- private type (within scope of full view) (r).

begin
   null;                                                              -- OK.
end BA21A02_0;                                        -- Null statement (k).
