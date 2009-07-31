# $NetBSD: Makefile,v 1.2 2009/07/31 18:09:24 jihbed Exp $
#

DISTNAME=	python-memcached-1.44
PKGNAME=	${PYPKGPREFIX}-lib${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.tummy.com/pub/python-memcached/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.tummy.com/Community/software/python-memcached/
COMMENT=	Python memcached client
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "../../devel/libmemcache/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
