# $NetBSD$

DISTNAME=	esp-1.27.x
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=	crosstool-NG
GITHUB_TAG=	refs/heads/esp-1.26.x
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espressif/crosstool-NG/
COMMENT=	Cross compiler build for espressif esp32 processors
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=	${WRKDIR}/crosstool-NG-esp-1.27.x

.include "../../mk/bsd.pkg.mk"

CONFIGURE_ARGS+=	--without-ncursesw

pre-configure:
	cd ${WRKSRC} && ./bootstrap
