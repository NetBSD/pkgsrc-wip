

     --==================================================================--

 
package body ImpDef.Annex_G is

   -- NOTE: These are example bodies.  It is expected that implementors
   --       will write their own versions of these routines.

--=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====--

   -- This function must return a negative zero value for implementations
   -- for which Float'Signed_Zeros is True.
   --
   -- The default body simply returns a negated literal 0.0.  If the
   -- default body does not return the value corresponding to a negatively
   -- signed zero for the implementation under test, it must be replaced
   -- by one which does.  See RM A.5.3(13).

   function Negative_Zero return Float is
   begin
      return -0.0;      -- Note: If this value is not negative zero for the
                        --       implementation, use of this "default" value
                        --       could result in false failures in
                        --       implementations where Float'Signed_Zeros
                        --       is True.

   -- ^^^^^^^^^^^^^^^^^^^^  MODIFY THIS BODY AS NEEDED  ^^^^^^^^^^^^^^^^^^^^

   end Negative_Zero;

--=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====--

end ImpDef.Annex_G;
