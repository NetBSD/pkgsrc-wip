# $NetBSD$

DISTNAME=	CNFgen-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/69/77/cc550fb40563ea69341ae17f2a0021f584259b5e885c493fdff570f619e8/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://massimolauria.github.io/cnfgen
COMMENT=	CNF formula generator
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.11:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

WRKSRC=		${WRKDIR}/CNFgen-0.7.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
