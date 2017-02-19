# $NetBSD: Makefile,v 1.16 2016/12/04 05:17:15 ryoon Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-mysql-${QTVERSION}
COMMENT=	Qt5 MySQL plugin

CFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../wip/qt5-qtbase58/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake -o Makefile "QT.sql.enabled_features+=sql-mysql" "QMAKE_LIBS_MYSQL=-lmysqlclient"

.include "../../wip/qt5-qtbase58/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
