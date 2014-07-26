# $NetBSD: Makefile,v 1.1 2014/07/26 09:50:17 jihbed Exp $

DISTNAME=	nupic-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://pypi.python.org/packages/source/n/nupic/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/numenta/nupic
COMMENT=	Numenta Platform for Intelligent Computing
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
