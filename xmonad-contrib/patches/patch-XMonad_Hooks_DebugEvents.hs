$NetBSD: patch-XMonad_Hooks_DebugEvents.hs,v 1.1 2013/02/26 22:17:45 szptvlfn Exp $

for wip/hs-x11-1.6.1.1

--- XMonad/Hooks/DebugEvents.hs.orig	2013-01-01 01:32:44.000000000 +0000
+++ XMonad/Hooks/DebugEvents.hs
@@ -29,6 +29,7 @@ import           XMonad.Hooks.DebugKeyEv
 import           XMonad.Util.DebugWindow                     (debugWindow)
 
 -- import           Graphics.X11.Xlib.Extras.GetAtomName        (getAtomName)
+import           Graphics.X11.Xlib.Atom                      ()
 
 import           Control.Exception.Extensible         as E
 import           Control.Monad.State
@@ -42,27 +43,12 @@ import           Codec.Binary.UTF8.Strin
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
