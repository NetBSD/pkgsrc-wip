# $NetBSD: Makefile,v 1.2 2010/01/18 09:38:30 thomasklausner Exp $
#

DISTNAME=	QScintilla-gpl-2.4
PKGNAME=	qt4-qscintilla-2.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.riverbankcomputing.com/static/Downloads/QScintilla2/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://www.riverbankcomputing.com/static/Downloads/QScintilla2/
COMMENT=	Scintilla C++ editor class for Qt
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=                 ${WRKDIR}/${DISTNAME}/Qt4

USE_TOOLS+=             gmake
USE_LIBTOOL=            yes
USE_LANGUAGES=	c++

MAKE_ENV+=      QTPREFIX=${QTDIR:Q}

INSTALLATION_DIRS=      ${QTDIR}/lib ${QTDIR}/include

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/libqscintilla2.la ${DESTDIR}${QTDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/Qsci/qsci*.h ${DESTDIR}${QTDIR}/include

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
