# $NetBSD: Makefile,v 1.3 2018/08/22 09:43:57 wiz Exp $

GIT_COMMIT=	2d673e1a76c9e6fa504a03444ba53913f1ef872d
DISTNAME=	${GIT_COMMIT}
PKGNAME=	velox-0.0.20190810
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/velox/archive/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	velox-${GIT_COMMIT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/velox
COMMENT=	simple window manager based on swc
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

WRKSRC=		${WRKDIR}/velox-${GIT_COMMIT}

PKGCONFIG_OVERRIDE+=	velox.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
.include "../../wip/libepoll-shim/buildlink3.mk"
.endif

.include "../../wip/swc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
