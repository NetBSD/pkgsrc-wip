# $NetBSD$

GITHUB_PROJECT=	u-boot
GITHUB_TAG=	refs/tags/v2023.04
DISTNAME=	v2023.04
PKGNAME=	${GITHUB_PROJECT}-tools-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=u-boot/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/u-boot/u-boot/
COMMENT=	U-Boot tools
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
USE_LANGUAGES=	c
USE_TOOLS+=	gmake

BUILD_TARGET=	defconfig oldconfig tools-only

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	tools/Makefile
SUBST_VARS.prefix=	PREFIX

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL} ${WRKSRC}/tools/dumpimage ${DESTDIR}${PREFIX}/bin
	${INSTALL} ${WRKSRC}/tools/mkimage ${DESTDIR}${PREFIX}/bin

.include "../../devel/libuuid/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
