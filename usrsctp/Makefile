# $NetBSD$

DISTNAME=	usrsctp-0.9.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sctplab/}
GITHUB_TAG=	refs/tags/${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sctplab/usrsctp/
COMMENT=	Portable SCTP userland stack
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	usrsctp.pc.in

WRKSRC=		${WRKDIR}/${DISTNAME}

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_FLAGS="${CMAKE_C_FLAGS} -fPIC"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
