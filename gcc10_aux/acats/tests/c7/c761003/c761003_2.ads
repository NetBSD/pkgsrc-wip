
------------------------------------------------------------------ C761003_2

with C761003_1;
package C761003_2 is

  type Global is new C761003_1.Global with null record;
  -- inherits Initialize and Finalize

  type Second is new C761003_1.Second with null record;
  -- inherits Initialize and Finalize

end C761003_2;
