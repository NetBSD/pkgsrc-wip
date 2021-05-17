

     --==================================================================--


-- The instantiation of C3A2A02_0 should NOT result in any exceptions.

with F3A2A00;
with C3A2A02_0;
pragma Elaborate (C3A2A02_0);
package C3A2A02_3 is new C3A2A02_0 (F3A2A00.Tagged_Type);
