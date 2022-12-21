# $NetBSD$

.include "../../wip/avidemux/Makefile.common"

PKGNAME=	${DISTNAME:S/_/-/}
COMMENT=	Graphical video editing program (Core)

USE_TOOLS+=	gmake perl

CMAKE_ARG_PATH=			${WRKSRC}/avidemux_core
CMAKE_MODULE_PATH_OVERRIDE=	${CMAKE_ARG_PATH}/CMakeLists.txt

post-configure:
	# By default, macOS uses a case-insensitive filesystem.
	# Then the following file is included by '#include<version>'.
	${RUN}${RM} -f ${WRKSRC}/${CONFIGURE_DIRS}/ffmpeg/source/VERSION

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
