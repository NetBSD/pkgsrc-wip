

-- No body for CC51004_0;


     --==================================================================--


with CC51004_0;  -- Matrix types.
generic          -- Generic matrix "clear" operation.
   type Squares is new CC51004_0.Sq_Type with private;       -- Indefinite
procedure CC51004_1 (Sq : in out Squares);                   -- formal.
