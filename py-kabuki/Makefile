# $NetBSD: Makefile,v 1.1 2014/07/26 18:35:37 jihbed Exp $

DISTNAME=	kabuki-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kabuki/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/hddm-devs/kabuki
COMMENT=	Easy creation of hierarchical bayesian models
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
