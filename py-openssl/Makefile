# $NetBSD: Makefile,v 1.1.1.1 2004/12/16 16:52:04 goteki Exp $
# 

DISTNAME=	pyOpenSSL-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyOpenSSL/openssl/}
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=	goteki@users.sourceforge.net
HOMEPAGE=	http://pyopenssl.sourceforge.net/
COMMENT=	Python OpenSSL framework

PYTHON_VERSIONS_ACCEPTED=23pth 22pth

PY_PATCHPLIST= 	yes
USE_BUILDLINK3= yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py install)

.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
