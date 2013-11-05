# $NetBSD: Makefile,v 1.1 2013/11/05 17:46:51 jihbed Exp $

DISTNAME=	recluse-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/r/recluse/
FETCH_USING=	curl

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/lamber/recluse
COMMENT=	Reproducible Experimentation for Computational Linguistics Use
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

post-extract:
	${MV} ${WRKSRC}/scripts/nltkbasedsegmentertokeniserrunner ${WRKSRC}/scripts/nltkbasedsegmentertokeniserrunner${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-nltk-[0-9]*:../../wip/py-nltk
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../wip/py-regex
.include "../../mk/bsd.pkg.mk"
