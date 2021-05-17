
SEPARATE (B38103D)
PACKAGE BODY B38103D1 IS

     TYPE T1A (D1 : I := V) IS          -- ERROR: (L) D1.          {6}
          RECORD NULL; END RECORD;

     TYPE T1B (D : I1 := V) IS          -- OK: (C) I1.             {6}
          RECORD NULL; END RECORD;

     TYPE T2A (D : I := V1) IS          -- ERROR: (B) V1.          {6}
          RECORD NULL; END RECORD;

     TYPE T2B (D : I1 := (VV1)) IS      -- ERROR: (M) ()'S.        {6}
          RECORD NULL; END RECORD;

     TYPE T3 (D1 : I; D2, D3 : I) IS    -- OK: (H) D1, D2.         {6}
          RECORD NULL; END RECORD;

     TYPE T4A (D : BOOLEAN :=
                   (TRUE = TRUE)) IS    -- ERROR: (E) AMBIGUOUS    {1:6}
                                             --   TRUE.
          RECORD NULL; END RECORD;

     TYPE T4B (D : BOOLEAN :=
          (TRUE = BOOLEAN'(TRUE))) IS   -- ERROR: (M)              {1:6}
                                             --   QUALIFICATION.
          RECORD NULL; END RECORD;

     TYPE T7A (D : I1 := WW1) IS        -- ERROR: (B) WW1.         {6}
          RECORD NULL; END RECORD;

     TYPE T7B (D : I := P1.W2) IS       -- OK: (A) P1.W2.          {6}
          RECORD NULL; END RECORD;

     TYPE T8A (D : I2 := W2) IS         -- OK: (A) I2, W2.         {6}
          RECORD NULL; END RECORD;

     TYPE T9A (D : I := 0 + 2) IS       -- ERROR: (G) 0 + 2.       {6}
          RECORD NULL; END RECORD;

     TYPE T9B (D : I2 := W2) IS         -- ERROR: (L) W2.          {6}
          RECORD NULL; END RECORD;

     TYPE T9C (D : I2 := "+"(2,0)) IS   -- OK by Ada95 rules.      {6}
          RECORD NULL; END RECORD;

     TYPE T10 (D : BOOLEAN := FALSE) IS -- ERROR: (E) DIFFERENT    {6}
                                        --   FALSE.
          RECORD NULL; END RECORD;

     TYPE T11 (D : STANDARD.BOOLEAN := STANDARD.FALSE) IS -- OK: (A) {6}
                                                          -- STANDARD.
          RECORD NULL; END RECORD;

     TYPE T12A (D : INTEGER := 00100) IS     -- OK: (D) 00100.     {6}
          RECORD NULL; END RECORD;

     TYPE T12B (D : INTEGER := 8#144#) IS    -- OK: (D) 8#144#.    {6}
          RECORD NULL; END RECORD;

     TYPE T13 (D :                      -- OK: (K) NEW COMMENT.
                   INTEGER              -- OK: (K) DIFFERENT
                                        --   COMMENT.
                   := 0
              ) IS                      -- OK. {5:6}
          RECORD NULL; END RECORD;

     TYPE T14 (D : INTEGER := 3 * 1) IS -- ERROR: (N) DIFFERENT *. {6}
          RECORD NULL; END RECORD;

     TYPE T15 (D : INTEGER := 3 / 1) IS -- ERROR: (N) DIFFERENT /. {6}
          RECORD NULL; END RECORD;

     TYPE T16A (D : P3.T) IS            -- OK: (A) P3.T.           {6}
          RECORD NULL; END RECORD;

     TYPE T16B (D : T) IS               -- OK: (A) T.              {6}
          RECORD NULL; END RECORD;

     TYPE T16C (D : NP3.T) IS           -- OK: (I) NP3.            {6}
          RECORD NULL; END RECORD;

     TYPE T17 (D : B38103D.P3.T) IS     -- OK: (I) B38103D.P3.T.   {6}
          RECORD NULL; END RECORD;

     TYPE T18 (D : I := F1(1,0)) IS     -- ERROR: (E) DIFFERENT F1. {6}
          RECORD NULL; END RECORD;

     TYPE T19A (D : I := STANDARD."+"(1,0)) IS    -- OK: (O)       {6}
                                                  --  STANDARD."+".
          RECORD NULL; END RECORD;

     TYPE T19B (D : CHARACTER := 'A') IS          -- OK: (O) 'A'.  {6}
          RECORD NULL; END RECORD;

     TYPE T19C (D : CHARACTER := STANDARD.'A') IS -- OK: (O)       {6}
                                                  --  STANDARD.'A'.
          RECORD NULL; END RECORD;

     TYPE T20A (D : P5.I) IS            -- OK: (P) P5.I.           {6}
          RECORD NULL; END RECORD;

     TYPE T20B (D : I := P5.V1) IS      -- ERROR: (P) P5.V1.       {6}
          RECORD NULL; END RECORD;

     TYPE T21A (D : I := 0) IS          -- ERROR: (Q) := 0.        {6}
          RECORD NULL; END RECORD;

     TYPE T21B (D : I) IS               -- ERROR: (Q) MISSING := 0. {6}
          RECORD NULL; END RECORD;

     TYPE T22 IS NEW RD;                -- ERROR: (R) MISSING      {6;1}
                                        --   DISCRIMINANT PART,
                                        --   NEW RD.

     TYPE T23 IS                        -- ERROR: (S) MISSING      {6}
                                        --   DISCRIMINANT PART.
         RECORD
               D : I := 0;              -- OPTIONAL ERROR:         {16;1}
         END RECORD;                    --   CONFLICT WITH INCOMP DECL.

     TYPE T24 (D : I := 0) IS NEW R;    -- ERROR: (T) NEW R.       {6;1}

END B38103D1;
