# $NetBSD: Makefile,v 1.2 2015/04/13 23:22:01 othyro Exp $

DISTNAME=	AIKIF-0.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=A/AIKIF/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/acutesoftware/AIKIF
COMMENT=	Artificial Intelligence Knowledge Information Framework
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 27
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
