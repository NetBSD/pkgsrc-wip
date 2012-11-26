# $NetBSD: Makefile,v 1.10 2012/11/26 01:05:10 fwsf Exp $

DISTNAME=	qt-creator-2.5.2-src
PKGNAME=	${DISTNAME:S/qt-/qt/:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	http://get.qt.nokia.com/qtcreator/
EXTRACT_SUFX=	.tar.gz
EXTRACT_USING=	bsdtar

MAINTAINER=	fw@submerge.ch
HOMEPAGE=	http://qt-project.org/
COMMENT=	Cross-platform IDE for Qt and C++
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin lib/qtcreator lib/qtcreator/plugins/Nokia \
			share/doc/qtcreator share/pixmaps share/qtcreator \
			share/qtcreator/translations
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	qt4-tools>=4.7.4:../../x11/qt4-tools \
		qt4-sqlite3>=4.7.4:../../x11/qt4-sqlite3

BUILD_TARGET=	all docs
INSTALL_TARGET=	install install_docs
MAKE_ENV+=	PREFIX=${PREFIX} INSTALL_ROOT=${DESTDIR}
CONFIGURE_ENV+=	PREFIX=${PREFIX}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
