# $NetBSD: Makefile,v 1.1 2015/08/05 21:31:17 jihbed Exp $

DISTNAME=	pyicane-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyicane/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/predicador37/pyicane
COMMENT=	Python wrapper for ICANE Statistical Data and Metadata API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.16.2:../../math/py-pandas

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
