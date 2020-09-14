# $NetBSD$

DISTNAME=	yaspin-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ac/af/0b1430abcffa44a5376a13f0e95912f89145facb528ef08c801f71e9bbd0/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pavdmyt/yaspin
COMMENT=	Yet Another Terminal Spinner
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-six>=1.6:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
