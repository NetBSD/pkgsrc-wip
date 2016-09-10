# $NetBSD$

DISTNAME=	recommonmark-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www textproc
MASTER_SITES=	https://pypi.python.org/packages/3d/95/aa1085573adf3dc7b164ae8569d57b1af5e98922e40345bb7efffed5ad2e/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/recommonmark
COMMENT=	The ReCommonMark Markdown spec
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.7.2:../../wip/py-commonmark

WRKSRC=		${WRKDIR}/recommonmark-0.4.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
