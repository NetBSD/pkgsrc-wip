# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.kvirc
PKG_SUPPORTED_OPTIONS=	inet6 kde python
PKG_SUGGESTED_OPTIONS=	inet6 kde

.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Minet6)
CMAKE_CONFIGURE_ARGS+=	-DWANT_IPV6=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_IPV6=OFF
# Required by x11/qt5-webengine?
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
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
