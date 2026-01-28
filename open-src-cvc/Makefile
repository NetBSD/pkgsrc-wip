# $NetBSD$

DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-700c-1.12
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=cambridgehackers/}
GITHUB_PROJECT=	open-src-cvc
GITHUB_TAG=	b3e7fded6d4d79491886de40aec3a780efdd9d4e
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cambridgehackers/open-src-cvc/
COMMENT=	Mirror of tachyon-da cvc Verilog simulator
#LICENSE=	#OSS CVC dual licensing modified Artistic Open Source Software License

WRKSRC=		${WRKDIR}/open-src-cvc-${GITHUB_TAG}/src
USE_LANGUAGES=	c
USE_TOOLS+=	gmake

MKPIE_SUPPORTED=	no
INSTALLATION_DIRS=	bin

MAKE_FILE=	makefile.cvc64
BUILD_TARGET=	cvc64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvc64 ${DESTDIR}${PREFIX}/bin/cvc

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
