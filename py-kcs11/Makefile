# $NetBSD: Makefile,v 1.1.1.1 2009/06/17 23:22:44 jihbed Exp $
#

DISTNAME=	PyKCS11-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pkcs11wrap/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.bit4id.org/trac/pykcs11
COMMENT=	PKCS\#11 wrapper for Python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
