# $NetBSD$

DISTNAME=	textosaurus-0.9.13
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=martinrotter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinrotter/textosaurus/
COMMENT=	Cross-platform text editor based on Qt and Scintilla
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake -o Makefile build.pro -r CONFIG+=release PREFIX=${PREFIX}

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
