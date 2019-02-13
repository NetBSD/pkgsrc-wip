# $NetBSD$

GITHUB_PROJECT= haxm
GITHUB_TAG=     c072ad9b68e1d558a9fb791511468d10a1a9b319
DISTNAME=       haxm-0.${GITHUB_TAG}
CATEGORIES=     emulators
MASTER_SITES=   ${MASTER_SITE_GITHUB:=intel/}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/intel/haxm/
COMMENT=	Intel Hardware Accelerated Execution Manager
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/haxm-${GITHUB_TAG}

OSVERSION_SPECIFIC=	YES

.include "../../mk/bsd.pkg.mk"
