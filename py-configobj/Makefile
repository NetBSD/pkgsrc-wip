# $NetBSD: Makefile,v 1.13 2014/10/10 14:43:58 jonperkin Exp $
#

DISTNAME=	configobj-4.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/c/configobj/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.voidspace.org.uk/python/configobj.html
COMMENT=	Simple but powerful config file reader and write
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

# XXX: as of configobj-4.7.2
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # "except Exception, e:" SyntaxError

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
