# $NetBSD: $

DISTNAME=	rkbin
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockchip-linux/}
GITHUB_TAG=	f43a462e7a1429a9d407ae52b4745033034a6cf9


MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockchip-linux/rkbin
COMMENT=	Rockchip loader binaries
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	libdata/rkbin
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/libdata/rkbin/rk35
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}-${GITHUB_TAG}/bin/rk35/* \
		${DESTDIR}${PREFIX}/libdata/${PKGNAME}/rk35

.include "../../mk/bsd.pkg.mk"
