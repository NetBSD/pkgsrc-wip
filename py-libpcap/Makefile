# $NetBSD: Makefile,v 1.2 2003/06/07 14:26:08 cjep Exp $
#

DISTNAME=	pylibpcap-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://pylibpcap.sourceforge.net/
COMMENT=	Python module for libpcap

PY_PATCHPLIST=	yes
USE_BUILDLINK2=	yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py install)

.include "../../lang/python/extension.mk"
.include "../../devel/swig-python/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
