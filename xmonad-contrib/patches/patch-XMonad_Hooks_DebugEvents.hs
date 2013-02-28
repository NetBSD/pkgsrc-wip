$NetBSD: patch-XMonad_Hooks_DebugEvents.hs,v 1.2 2013/02/28 15:27:50 szptvlfn Exp $

for wip/hs-x11-1.6.1.1
refine on this patch, from http://code.haskell.org/XMonadContrib/

--- XMonad/Hooks/DebugEvents.hs.orig    2013-01-01 01:32:44.000000000 +0000
+++ XMonad/Hooks/DebugEvents.hs
@@ -42,27 +42,12 @@ import           Codec.Binary.UTF8.Strin
 import           Data.Maybe                                  (fromMaybe)
 import           Data.Monoid
 import           Foreign
-import           Foreign.C.String
 import           Foreign.C.Types
 import           Numeric                                     (showHex)
 import           System.Exit
 import           System.IO
 import           System.Process

--- this should move into X11
-foreign import ccall unsafe "XGetAtomName"
-  xGetAtomName :: Display -> Atom -> IO CString
-
-getAtomName     :: Display -> Atom -> IO (Maybe String)
-getAtomName d a =  do
-  n <- xGetAtomName d a
-  if n == nullPtr
-    then return Nothing
-    else do
-      n' <- peekCString n
-      xFree n
-      return $ Just n'
-
 -- | Event hook to dump all received events.  You should probably not use this
 --   unconditionally; it will produce massive amounts of output.
 debugEventsHook   :: Event -> X All
