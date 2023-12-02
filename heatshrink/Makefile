# $NetBSD$

DISTNAME=	heatshrink-0.4.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=atomicobject/}
GITHUB_PROJECT=	heatshrink
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://github.com/atomicobject/heatshrink
COMMENT=	Data compression library for embedded/real-time systems
LICENSE=	isc

USE_CMAKE=		yes
USE_TOOLS+=		cmake gmake
INSTALLATION_DIRS+=	bin include lib

post-extract:
	${CP} ${FILESDIR}/CMakeLists.txt ${FILESDIR}/Config.cmake.in ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
