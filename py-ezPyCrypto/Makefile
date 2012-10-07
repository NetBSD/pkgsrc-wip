# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:33 asau Exp $
#

DISTNAME=	ezPyCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/ezPyCrypto/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.freenet.org.nz/ezPyCrypto/
COMMENT=	Easy Python API for strong encryption
#LICENSE=	# TODO: (see mk/license.mk)

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
