# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:45 thomasklausner Exp $

DISTNAME=	recluse-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/recluse/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/lamber/recluse
COMMENT=	Reproducible Experimentation for Computational Linguistics Use
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-nltk-[0-9]*:../../wip/py-nltk
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../textproc/py-regex

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/nltkbasedsegmentertokeniserrunner ${WRKSRC}/scripts/nltkbasedsegmentertokeniserrunner${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
