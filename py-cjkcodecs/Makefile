# $NetBSD: Makefile,v 1.3 2004/01/04 23:29:48 minskim Exp $
#

DISTNAME=	cjkcodecs-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://download.berlios.de/cjkpython/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://cjkpython.berlios.de/
COMMENT=	Python Unicode codecs for Chinese, Japanese, and Korean encodings

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
USE_BUILDLINK2=	yes

post-install:
	@strip ${LOCALBASE}/${PYSITELIB}/cjkcodecs/*.so

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
