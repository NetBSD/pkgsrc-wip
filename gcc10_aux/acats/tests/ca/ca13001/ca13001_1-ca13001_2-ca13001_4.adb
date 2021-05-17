
     --==================================================================--

-- Context clause required for visibility needed by a separate subunit.

with CA13001_1.CA13001_2.CA13001_3;    -- Public sibling.

package body CA13001_1.CA13001_2.CA13001_4 is

   protected body Family_Transportation is separate;

end CA13001_1.CA13001_2.CA13001_4;
