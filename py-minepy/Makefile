# $NetBSD: Makefile,v 1.1 2014/01/14 17:52:32 jihbed Exp $

DISTNAME=	minepy-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/source/m/minepy/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	minepy.sourceforge.net
COMMENT=	Maximal Information-based Nonparametric Exploration
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/minepy-1.0.0

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/minepy/scripts/mine ${WRKSRC}/minepy/scripts/mine${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
