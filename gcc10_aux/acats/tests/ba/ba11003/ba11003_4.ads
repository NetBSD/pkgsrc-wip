                                             -- parent is not a library package
     ---------------------------------------------------------------------

package BA11003_4 is
 
   -- Nested package as a parent.

   package BA11003_5 is

      My_Exception : Exception;

   end BA11003_5;

   -- ... Other package, subprogram definitions.

end BA11003_4;
