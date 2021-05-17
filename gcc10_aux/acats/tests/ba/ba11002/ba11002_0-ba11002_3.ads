                            -- Private_Integer not visible here

function BA11002_0.BA11002_3 (Int : Private_Integer)   -- ERROR:
  return Visible_Integer;   -- Private_Integer not visible here            
