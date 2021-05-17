

     --==================================================================--


-- Library-level instantiation. Actual parameter is record extension.

with C340A02_0;  -- Extended book abstraction.
with F340A000;   -- Singly-linked list abstraction.
package C340A02_2 is new F340A000
  (Parent_Type => C340A02_0.Detailed_Book_Type);
