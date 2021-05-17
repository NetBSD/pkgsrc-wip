

-- No body for C730A02_1.


     --==================================================================--


-- Library-level instantiation. Actual parameter is private extension.

with C730A02_0;  -- Extended book abstraction.
with F730A000;   -- Singly-linked list abstraction.
package C730A02_2 is new F730A000
  (Parent_Type => C730A02_0.Detailed_Book_Type);
