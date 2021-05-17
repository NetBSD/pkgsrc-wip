
     --=================================================================--

-- Child of a generic package must be a generic package. 

package BA11003_7.BA11003_8 is                                        -- ERROR:
                                                          -- parent is generic
   My_Boolean : Boolean := True;
end;
