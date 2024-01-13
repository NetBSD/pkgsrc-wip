# $NetBSD$

DISTNAME=		sabctools-${DISTVERSION}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
DISTVERSION=		8.1.0
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_GITHUB:=sabnzbd/}
GITHUB_PROJECT=		sabctools
GITHUB_TAG=		v${DISTVERSION}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://sabnzbd.org/
COMMENT=	C implementations of functions for use within SABnzbd
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND modified-bsd AND mit

USE_LANGUAGES+=	c c++

TOOL_DEPENDS+=  ${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=  ${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
#.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
