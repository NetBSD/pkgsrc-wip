# $NetBSD$

GITHUB_PROJECT=	vid.stab
DISTNAME=	release-0.98b
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	libvidstab-0.98b
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=georgmartius/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://public.hronopik.de/vid.stab/
COMMENT=	Video stabilization library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/vid.stab-release-0.98b
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
