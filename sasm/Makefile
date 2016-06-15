# $NetBSD$

DISTNAME=	SASM-3.5.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Dman95/}
GITHUB_PROJECT=	SASM
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Dman95/SASM/
COMMENT=	Simple crossplatform IDE for NASM, MASM, GAS and FASM
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${RUN} cd ${WRKSRC} && ${PKGSRC_ENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake PREFIX=${PREFIX} -o Makefile

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
