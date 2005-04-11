# $NetBSD: Makefile,v 1.4 2005/04/11 21:15:16 tvierling Exp $
#

DISTNAME=	pylibpcap-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pylibpcap/}

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://pylibpcap.sourceforge.net/
COMMENT=	Python module for libpcap

PY_PATCHPLIST=	yes

do-build:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py build)

do-install:
	(cd ${WRKSRC} && ${PYTHONBIN} setup.py install)

.include "../../lang/python/extension.mk"
.include "../../devel/swig-python/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
