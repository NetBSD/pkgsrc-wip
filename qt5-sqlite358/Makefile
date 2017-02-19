# $NetBSD: Makefile,v 1.18 2016/12/04 05:17:17 ryoon Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-sqlite3-${QTVERSION}
COMMENT=	Qt5 SQLite3 plugin

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

OPSYSVARS+=    USE_LANGUAGES
USE_LANGUAGES.SunOS+=	c99
CFLAGS.SunOS+= -D__EXTENSIONS__        # posix_fallocate()

.include "../../wip/qt5-qtbase58/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake -d -o Makefile "QT.sql.enabled_features+=sql-sqlite" "QT.sql.enabled_features+=system-sqlite" "QMAKE_LIBS_SQLITE=-lsqlite3"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/qt5-qtbase58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
