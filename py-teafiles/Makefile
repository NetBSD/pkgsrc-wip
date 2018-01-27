# $NetBSD: Makefile,v 1.1 2012/11/09 18:34:24 jihbed Exp $
#

DISTNAME=	teafiles-0.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math finance
MASTER_SITES=	${MASTER_SITE_PYPI:=t/teafiles/}
EXTRACT_SUFX=	.zip#md5=c6a4cca7fff1e5a5d01c2c59b3339b04

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://discretelogics.com/
COMMENT=	Time Series storage in flat files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
