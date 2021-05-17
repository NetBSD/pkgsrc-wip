

     --==================================================================--


with F3A2A00;
generic
   type FD  is new F3A2A00.Tagged_Type with private;
   type FAF is access all FD;
   FObj : in out FD;
package C3A2A01_1 is
   procedure Handle (R: out F3A2A00.TC_Result_Kind);
end C3A2A01_1;
