# $NetBSD$

DISTNAME=	CommonMark-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www textproc
MASTER_SITES=	https://pypi.python.org/packages/6b/6b/9f711705fd36259a47ae7b5a4feeea664eea46d3a54856bbda00de7f119c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rtfd/CommonMark-py
COMMENT=	Python parser for the CommonMark Markdown spec
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-future>=0.15.2:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-hypothesis>=3.4.2:../../devel/py-hypothesis

WRKSRC=		${WRKDIR}/CommonMark-0.7.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
