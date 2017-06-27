# $NetBSD$

GITHUB_PROJECT=	ngs
DISTNAME=	1.2.3
PKGNAME=	ngs-sdk-all-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=ncbi/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	${MASTER_SITE_GITHUB:=ncbi/ngs/}
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)
.include "../../biology/ngs-sdk/buildlink3.mk"

#DEPENDS+=	ngs-sdk
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_TOOLS+=	gmake perl:build
USE_LANGUAGES=	c c++
BUILD_TARGET=	default
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
repatch:
	mkpatches
	${MAKE} mps
	${MAKE} clean
	${MAKE} configure

remake:
	${MAKE} clean
	${MAKE} configure
