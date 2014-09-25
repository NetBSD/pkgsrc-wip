# $NetBSD: Makefile,v 1.1 2014/09/25 17:46:26 nros Exp $
#

DISTNAME=	QScintilla-gpl-2.8.4
PKGNAME=	qt5-${DISTNAME:tl:S/-gpl-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyqt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.riverbankcomputing.co.uk/software/qscintilla/intro
COMMENT=	Scintilla C++ editor class for Qt5
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}/Qt4Qt5

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++

MAKE_ENV+=	QTPREFIX=${QTDIR}
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	(cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro)

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
