# $NetBSD$

DISTNAME=	mozversion-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://files.pythonhosted.org/packages/2e/89/2b8669a488d2c33c7ee7135a3efa66a43f34f32c7d74049d424eddbb3331/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.mozilla.org/Auto-tools/Projects/Mozbase
COMMENT=	Library to get version information for applications
LICENSE=	mpl-2.0

DEPENDS+=	# TODO: mozlog>=6.0
DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
