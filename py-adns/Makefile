DISTNAME=       adns-python-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     net
MASTER_SITES=   http://dustman.net/andy/python/adns-python/1.0.0/

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://dustman.net/andy/python/adns-python/
COMMENT=        The adns module provides an interface to the GNU adns asynchronous DNS resolver library.

PYDISTUTILSPKG= 
USE_BUILDLINK2= yes


.include "../../net/adns/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

