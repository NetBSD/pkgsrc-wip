# $NetBSD$

DISTNAME=	release-0.98b
PKGNAME=	libvidstab-0.98b
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=georgmartius/}
GITHUB_PROJECT=	vid.stab
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://public.hronopik.de/vid.stab/
COMMENT=	Video stabilization library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/vid.stab-release-0.98b
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
