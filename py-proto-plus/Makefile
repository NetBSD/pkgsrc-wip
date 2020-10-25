# $NetBSD$

DISTNAME=	proto-plus-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/75/0d/dd8e8c979eb843b873aeaadcfefd5383da7e2fc5593456a32264cae1cc5c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/googleapis/proto-plus-python.git
COMMENT=	Beautiful, Pythonic protocol buffers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-protobuf>=3.12.0:../../devel/py-protobuf

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
