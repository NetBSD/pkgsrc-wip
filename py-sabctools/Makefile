# $NetBSD$

DISTNAME=		sabctools-${DISTVERSION}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
DISTVERSION=		7.0.2
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_GITHUB:=sabnzbd/}
GITHUB_PROJECT=		sabctools
GITHUB_TAG=		v${DISTVERSION}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://sabnzbd.org/
COMMENT=	C implementations of functions for use within SABnzbd
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

USE_LANGUAGES+=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
#.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
