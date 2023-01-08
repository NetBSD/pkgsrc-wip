# $NetBSD$

.include "../../wip/avidemux/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-qt-/}

COMMENT=	Graphical video editing program (QT UI)

CMAKE_ARG_PATH=			${WRKSRC}/avidemux/qt4
CMAKE_MODULE_PATH_OVERRIDE=	${CMAKE_ARG_PATH}/CMakeLists.txt

.include "../../devel/zlib/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../wip/avidemux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
