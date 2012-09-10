# $NetBSD: Makefile,v 1.3 2012/09/10 09:12:17 jihbed Exp $
#

DISTNAME=	mocker-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://launchpad.net/mocker/trunk/1.1/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://labix.org/mocker
COMMENT=	Graceful platform for test doubles in Python
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
