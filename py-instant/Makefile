# $NetBSD: Makefile,v 1.3 2012/10/07 11:54:45 asau Exp $
#

DISTNAME=	instant-1.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/instant/1.0.x/1.0.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/instant
COMMENT=	Instant inlining of C and C++ code in Python

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

# todo: depends on swig, distutils
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
