# $NetBSD: Makefile,v 1.1 2015/07/10 22:28:02 jihbed Exp $

DISTNAME=	vispy-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vispy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://vispy.org
COMMENT=	Interactive visualization in Python
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
