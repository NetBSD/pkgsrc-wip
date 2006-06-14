# $NetBSD: Makefile,v 1.2 2006/06/14 09:14:48 absd Exp $
#

PKGNAME=	sqlitebrowser-1.3
DISTNAME=	${PKGNAME}-src
CATEGORIES=	databases x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqlitebrowser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	QT3 lightweight GUI editor/viewer for SQLite Databases
HOMEPAGE=	http://sqlitebrowser.sourceforge.net/

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/sqlitebrowser

QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	QMAKE=${QMAKE:Q}
USE_LANGUAGES=		c++

BUILDLINK_DEPMETHOD.qt3-tools=  build

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

do-configure:
	(cd ${WRKSRC}; ${QMAKE} -o Makefile ${CONFIGURE_ARGS} sqlitedbbrowser.pro)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlitebrowser/sqlitebrowser ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
