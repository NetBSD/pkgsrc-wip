# $NetBSD$

GITHUB_PROJECT=	usrsctp
GITHUB_TAG=	0.9.5.0
DISTNAME=	0.9.5.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sctplab/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sctplab/usrsctp/
COMMENT=	A portable SCTP userland stack
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/usrsctp-0.9.5.0
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	usrsctp.pc.in

CMAKE_ARGS+= -DCMAKE_C_FLAGS="${CMAKE_C_FLAGS} -fPIC"

#.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
