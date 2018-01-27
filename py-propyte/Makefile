# $NetBSD$

DISTNAME=	propyte-2016.7.11.1839
PKGNAME=	${PYPKGPREFIX}-propyte-20167111839
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/18/53/60f626e6c360b66148ee160df5c65fa9b9f30cf45a8c28ecbde8069bc861/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/wdbm/propyte
COMMENT=	Template Python program
LICENSE=	gnu-gplv-3

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-prel-[0-9]*:../../wip/py-prel
DEPENDS+=	${PYPKGPREFIX}-technicolor-[0-9]*:../../wip/py-technicolor

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
