
-----------------------------------------------------------------------------

with C3A0009_0;
package C3A0009_1 is -- Emergency_Items
   package Push_Buttons renames C3A0009_0;

   procedure Emergency (B : in out Push_Buttons.Button);
end C3A0009_1;
