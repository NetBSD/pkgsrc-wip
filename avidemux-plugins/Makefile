# $NetBSD$

.include "../../wip/avidemux/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-plugins-/}
COMMENT=	Graphical video editing program (Plugins)

USE_TOOLS+=	tar

CHECK_SHLIBS_SUPPORTED=		no

CMAKE_ARG_PATH=			${WRKSRC}/avidemux_plugins
CMAKE_MODULE_PATH_OVERRIDE=	${CMAKE_ARG_PATH}/CMakeLists.txt

PLUGIN_UI=	COMMON SETTINGS

.if !empty(PKG_OPTIONS:Mcli)
PLUGIN_UI+=	CLI
.include "../../wip/avidemux-cli/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mqt4) || !empty(PKG_OPTIONS:Mqt5) || \
    !empty(PKG_OPTIONS:Mqt6)
PLUGIN_UI+=	QT4
.include "../../wip/avidemux-qt/buildlink3.mk"
.endif

CMAKE_CONFIGURE_ARGS+=	-DPLUGIN_UI="${PLUGIN_UI}"
#CMAKE_CONFIGURE_ARGS+=	-DCMAKE_FIND_DEBUG_MODE:BOOL=ON

.include "../../wip/avidemux/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
