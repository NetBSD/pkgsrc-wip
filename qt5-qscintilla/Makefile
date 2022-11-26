# $NetBSD: Makefile,v 1.15 2022/11/23 16:19:12 adam Exp $

.include "../../x11/qt5-qscintilla/Makefile.common"

PKGNAME=	qt5-${DISTNAME:S/_src//:tl}
COMMENT=	Scintilla C++ editor class for Qt5

BUILD_DIRS=	src

USE_TOOLS+=	gmake

MAKE_ENV+=	QTPREFIX=${QTDIR}
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC}/src && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro

.include "../../mk/bsd.pkg.mk"
