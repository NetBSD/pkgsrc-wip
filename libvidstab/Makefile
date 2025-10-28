# $NetBSD$

DISTNAME=	libvidstab-1.1.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=georgmartius/}
GITHUB_PROJECT=	vid.stab
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://public.hronopik.de/vid.stab/
COMMENT=	Video stabilization library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
