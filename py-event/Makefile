# $NetBSD: Makefile,v 1.4 2014/02/11 18:12:46 jihbed Exp $

DISTNAME=	event-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pyevent.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/pyevent/
COMMENT=	Python extension module for libevent
LICENSE=	modified-bsd

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
