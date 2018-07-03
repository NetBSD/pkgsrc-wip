# $NetBSD: Makefile,v 1.4 2014/02/11 18:12:46 jihbed Exp $

DISTNAME=	pyevent-0.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaraco/}
GITHUB_PROJECT=	pyevent

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/jaraco/pyevent
COMMENT=	Python extension module for libevent
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.4.3
BROKEN=		touches libevent internals
# event.c:4157:87: error: dereferencing pointer to incomplete type 'struct evbuffer'

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
