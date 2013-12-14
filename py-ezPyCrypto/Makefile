# $NetBSD: Makefile,v 1.3 2013/12/14 08:23:56 obache Exp $
#

DISTNAME=	ezPyCrypto-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://freenet.mcnabhosting.com/ezPyCrypto/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://freenet.mcnabhosting.com/ezPyCrypto/
COMMENT=	Easy Python API for strong encryption
#LICENSE=	gnu-gpl-v?

DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:R}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
