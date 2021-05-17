
-----------------------------------------------------------

package body B830001_10 is
   B830001_12 : Integer;                                              -- OK.
                                    -- Child B830001_12 is not visible here.
   procedure B830001_11 is separate;  
end B830001_10;
