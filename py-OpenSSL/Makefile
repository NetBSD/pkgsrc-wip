# $NetBSD: Makefile,v 1.2 2003/06/07 14:21:24 cjep Exp $
#

DISTNAME=	pyOpenSSL-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=     adam@monkeybyte.org
HOMEPAGE=       http://pyopenssl.sourceforge.net/
COMMENT=        Python interface to the OpenSSL library

PYDISTUTILSPKG=
PYBINMODULE=
USE_BUILDLINK2= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
