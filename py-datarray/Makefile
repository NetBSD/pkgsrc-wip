# $NetBSD: Makefile,v 1.3 2013/11/30 18:24:18 jihbed Exp $

DISTNAME=	datarray-0.0.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=d/datarray/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/fperez/datarray
COMMENT=	NumPy arrays with named axes and named indices
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
