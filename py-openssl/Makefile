# $NetBSD: Makefile,v 1.3 2004/12/27 23:20:40 minskim Exp $
# 

DISTNAME=	pyOpenSSL-0.6
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=pyopenssl/}

MAINTAINER=	goteki@users.sourceforge.net
HOMEPAGE=	http://pyopenssl.sourceforge.net/
COMMENT=	Python OpenSSL framework

PYTHON_VERSIONS_ACCEPTED=	24pth 23pth 22pth

USE_BUILDLINK3= yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
