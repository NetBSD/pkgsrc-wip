# $NetBSD: Makefile,v 1.10 2013/09/19 04:59:10 wongk Exp $
#

DISTNAME=	configobj-4.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/c/configobj/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.voidspace.org.uk/python/configobj.html
COMMENT=	Simple but powerful config file reader and write
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
