# $NetBSD$

GITHUB_PROJECT=	haxm
GITHUB_TAG=	c072ad9b68e1d558a9fb791511468d10a1a9b319
DISTNAME=	haxm-0.${GITHUB_TAG}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/intel/haxm/
COMMENT=	Intel Hardware Accelerated Execution Manager
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/haxm-${GITHUB_TAG}

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64
OSVERSION_SPECIFIC=	YES

BUILD_DIRS=	platforms/netbsd

BUILDLINK_PASSTHRU_DIRS+=	${BSDSRCDIR}/sys

BUILD_DEFS+=	BSDSRCDIR

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=address-of-packed-member
.endif

KMOD=		haxm.kmod
KMODULEDIR=	stand/${MACHINE}/${OS_VERSION}/modules

INSTALLATION_DIRS+=	${KMODULEDIR}

PLIST_SUBST+=	MACHINE=${MACHINE}

do-install:
	${RUN} cd ${WRKSRC}/platforms/netbsd && \
		${INSTALL_PROGRAM} ${KMOD} ${DESTDIR}${PREFIX}/${KMODULEDIR}

.include "../../mk/bsd.pkg.mk"
