# $NetBSD: Makefile,v 1.3 2015/07/04 03:04:36 jihbed Exp $

DISTNAME=	gitdb-0.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitdb/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/gitpython-developers/gitdb
COMMENT=	Git Object Database
LICENSE=	modified-bsd #Probably

DEPENDS+=	${PYPKGPREFIX}-smmap>=0.8.4:../../wip/py-smmap

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
