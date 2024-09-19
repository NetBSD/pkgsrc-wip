# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	sciproc-0.7.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sciproc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.nowebsite.com
COMMENT=	Process scientific multidimensional data
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
