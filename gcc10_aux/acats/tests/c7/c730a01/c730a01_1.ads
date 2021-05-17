

     --==================================================================--




     --==================================================================--


-- Library-level instantiation. Actual parameter is tagged record.

with F730A001;  -- Book definitions.
with F730A000;  -- Singly-linked list abstraction.
package C730A01_1 is new F730A000 (Parent_Type => F730A001.Book_Type);
