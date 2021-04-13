# $NetBSD$

PKGNAME=	elogind-246.10
GITHUB_PROJECT=	elogind
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_TAG}
CATEGORIES=	systools
MASTER_SITES=	${MASTER_SITE_GITHUB:=elogind/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://github.com/elogind/elogind/
COMMENT=	Fork of logind daemon from systemd
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/elogind-246.10
HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		m4

PKGCONFIG_OVERRIDE+=	src/libelogind/libelogind.pc.in

.include "../../wip/libudev/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
