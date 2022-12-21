# $NetBSD$

.include "../../wip/avidemux/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-cli-/}

COMMENT=	Graphical video editing program (CLI UI)

CMAKE_ARG_PATH=			${WRKSRC}/avidemux/cli
CMAKE_MODULE_PATH_OVERRIDE=	${CMAKE_ARG_PATH}/CMakeLists.txt

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/avidemux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
