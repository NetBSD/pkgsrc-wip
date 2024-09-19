# $NetBSD: Makefile,v 1.5 2012/10/07 13:57:26 asau Exp $
#

DISTNAME=	processing-0.52
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/processing/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pyprocessing.berlios.de/
COMMENT=	Library for running multiple Python processes using the threading API
LICENSE=	modified-bsd

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
