

     --==================================================================--


-- Library-level instantiation. Actual parameter is tagged record.

with F340A001;  -- Book definitions.
with F340A000;  -- Singly-linked list abstraction.
package C340A01_1 is new F340A000 (Parent_Type => F340A001.Book_Type);
