# $NetBSD: Makefile,v 1.1.1.1 2010/01/01 16:21:09 jihbed Exp $
#

DISTNAME=	ezPyCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://www.freenet.org.nz/ezPyCrypto/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.freenet.org.nz/ezPyCrypto/
COMMENT=	Easy Python API for strong encryption
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
