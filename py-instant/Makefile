# $NetBSD: Makefile,v 1.2 2012/05/11 22:27:47 outpaddling Exp $
#

DISTNAME=	instant-1.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/instant/1.0.x/1.0.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/instant
COMMENT=	Instant inlining of C and C++ code in Python

FETCH_USING=	curl

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

# todo: depends on swig, distutils
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
