# $NetBSD$

DISTNAME=	parserutils-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/c0/3d/20209d97be85fd524fdcc3ec225960d45626a43a283d104d78c53418787f/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/consbio/parserutils
COMMENT=	Collection of performant parsing utilities
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.4.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.5.3:../../time/py-dateutil

WRKSRC=		${WRKDIR}/parserutils-0.3.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
