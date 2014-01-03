# $NetBSD: Makefile,v 1.3 2014/01/03 21:41:13 jihbed Exp $

DISTNAME=	event-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pyevent.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/pyevent/
COMMENT=	Python extension module for libevent
LICENSE=	modified-bsd

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
