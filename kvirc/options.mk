# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.kvirc
PKG_SUPPORTED_OPTIONS=	inet6 kde qtwebengine python
PKG_SUGGESTED_OPTIONS=	inet6 kde qtwebengine

.include "../../mk/bsd.prefs.mk"

# x11/qt5-qtwebengine-5.15 (pkgsrc-2024Q3)
# does not build on NetBSD/i386 and sometimes on Linux
.if ${MACHINE_PLATFORM:MNetBSD-*-i386}
PKG_SUGGESTED_OPTIONS+=	-qtwebengine
.endif

.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Minet6)
CMAKE_CONFIGURE_ARGS+=	-DWANT_IPV6=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_IPV6=OFF
.endif


.if !empty(PKG_OPTIONS:Mkde)
CMAKE_CONFIGURE_ARGS+=	-DWANT_KDE=ON
TOOL_DEPENDS+=	extra-cmake-modules>=0:../../devel/extra-cmake-modules
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_KDE=OFF
.endif


.if !empty(PKG_OPTIONS:Mqtwebengine)
CMAKE_CONFIGURE_ARGS+=	-DWANT_QTWEBENGINE=ON
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
# exposed with -DWANT_IPV6=OFF
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_QTWEBENGINE=OFF
.endif


#
# [ 88%] Building CXX object src/modules/pythoncore/CMakeFiles/kvipythoncore.dir/libkvipythoncore.cpp.o
# In file included from /usr/pkgsrc/wip/kvirc/work/KVIrc-5.2.6/src/modules/pythoncore/libkvipythoncore.cpp:38:0:
# /usr/pkgsrc/wip/kvirc/work/KVIrc-5.2.6/src/modules/pythoncore/pythonheaderwrapper.h:10:10: fatal error: Python.h: No such file or directory
#  #include <Python.h>
#           ^~~~~~~~~~
# compilation terminated.
# *** [src/modules/pythoncore/CMakeFiles/kvipythoncore.dir/libkvipythoncore.cpp.o] Error code 1
#
.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/pyversion.mk"
PLIST_SRC+=	PLIST.python
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PYTHON=OFF
.endif
