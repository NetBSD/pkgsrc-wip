# $NetBSD: Makefile,v 1.1 2013/09/06 21:24:10 jihbed Exp $

DISTNAME=	mystic-0.2a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://dev.danse.us/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://trac.mystic.cacr.caltech.edu/project/mystic
COMMENT=	Simple interactive inversion analysis framework
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
