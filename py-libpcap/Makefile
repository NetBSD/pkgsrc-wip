# $NetBSD: Makefile,v 1.5 2006/01/23 22:20:52 adrian_p Exp $
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
.include "../../devel/swig/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
