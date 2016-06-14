# $NetBSD: Makefile,v 1.11 2012/12/15 08:27:24 asau Exp $

DISTNAME=	qt-creator-opensource-src-4.0.1
PKGNAME=	${DISTNAME:S/qt-/qt/:S/-opensource-src//}
CATEGORIES=	devel
MASTER_SITES=	http://download.qt.io/official_releases/${PKGBASE}/${PKGVERSION_NOREV:R}/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qt.io
COMMENT=	Cross-platform IDE for Qt and C++
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}/${PREFIX}
INSTALL_TARGET=		install install_inst_qch_docs

do-configure:
	${RUN} cd ${WRKSRC} && ${QTDIR}/bin/qmake -o Makefile

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
