# $NetBSD: Makefile,v 1.1.1.1 2003/10/01 02:01:33 minskim Exp $
#

DISTNAME=	cjkcodecs-1.0.1
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
