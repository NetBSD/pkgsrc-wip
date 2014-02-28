# $NetBSD: Makefile,v 1.1 2014/02/28 08:54:49 jihbed Exp $

DISTNAME=	PyMarkovChain-1.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/P/PyMarkovChain/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/P/PyMarkovChain/
COMMENT=	Simple markov chain implementation
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
