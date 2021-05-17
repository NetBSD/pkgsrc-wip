
-- No body for BA12004.

     --=================================================================--

with BA12004_0.BA12004_2;                                          -- ERROR:
                          -- Child BA12004_2 is not visible in this context.
package BA12004_7 is

  type Invisible is (A, B, C);

end BA12004_7;
