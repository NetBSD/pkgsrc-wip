# $NetBSD: Makefile,v 1.1 2015/06/01 22:06:44 jihbed Exp $

DISTNAME=	scs-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scs/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/cvxgrp/scs
COMMENT=	Scs: splittling cone solver
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
#DEPENDS+=	atlas>=3.11.11:../../wip/atlas
.include "../../mk/bsd.pkg.mk"
