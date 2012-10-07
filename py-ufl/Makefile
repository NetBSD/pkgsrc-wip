# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	ufl-1.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/ufl/1.0.x/1.0.0/+download/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/ufl
COMMENT=	Unified Form Language for finite element discretizations

FETCH_USING=	curl

LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

# todo: depends on swig, distutils
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
