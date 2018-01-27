# $NetBSD: Makefile,v 1.1 2014/06/28 20:39:28 jihbed Exp $

DISTNAME=	smcp-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=s/smcp/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://cvxopt.github.io/smcp
COMMENT=	Python extension for solving sparse matrix cone programs
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
DEPENDS+=	${PYPKGPREFIX}-chompack>=2.0.0:../../wip/py-chompack
DEPENDS+=	${PYPKGPREFIX}-cvxpy-[0-9]*:../../wip/py-cvxpy
.include "../../mk/bsd.pkg.mk"
