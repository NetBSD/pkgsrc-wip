# $NetBSD: Makefile,v 1.18 2016/12/04 05:17:15 ryoon Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-odbc-${QTVERSION}
COMMENT=	Qt5 odbc plugin

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

LIBS+=			-lltdl

.include "../../wip/qt5-qtbase58/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake -o Makefile "QT.sql.enabled_features+=sql-odbc" "QMAKE_LIBS_ODBC=-lodbc"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../wip/qt5-qtbase58/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
