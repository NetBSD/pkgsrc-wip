# $NetBSD$

DISTNAME=	liblarch-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	liblarch
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=getting-things-gnome/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/liblarch
COMMENT=	Python library for handling lists, trees and DAGs
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
