
-----------------------------------------------------------
with B830001_20;
package B830001_21 is
   type Tag is tagged record
      I : Integer;
   end record;

   package B830001_22 is new B830001_20 (Tag, Integer, Integer);      -- ERROR:
                       -- Visible part of instance contains illegal homographs.
end B830001_21;
