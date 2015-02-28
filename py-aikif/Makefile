# $NetBSD: Makefile,v 1.1 2015/02/28 16:49:32 jihbed Exp $

DISTNAME=	AIKIF-0.0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/A/AIKIF/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/acutesoftware/AIKIF
COMMENT=	Artificial Intelligence Knowledge Information Framework
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE= 26 27 33
PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
