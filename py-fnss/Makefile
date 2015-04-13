# $NetBSD: Makefile,v 1.2 2015/04/13 23:22:02 othyro Exp $

DISTNAME=	fnss-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/f/fnss/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://fnss.github.io/
COMMENT=	Fast creation and configuration of topologies, traffic matrices
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/fnss-0.5.0
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 33 34

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PY_PATCHPLIST=  yes

post-extract:
	${MV} ${WRKSRC}/bin/mn-fnss ${WRKSRC}/bin/mn-fnss${PYVERSSUFFIX}
	${MV} ${WRKSRC}/bin/fnss-troubleshoot ${WRKSRC}/bin/fnss-troubleshoot${PYVERSSUFFIX}

${PYPKGPREFIX}-mako>=0.8.1:../../devel/py-mako
.include "../../lang/python/egg.mk"
${PYPKGPREFIX}-networkx>=1.8.1:../../math/py-networkx
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
