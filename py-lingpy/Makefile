# $NetBSD: Makefile,v 1.4 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	lingpy-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lingpy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/l/lingpy/
COMMENT=	Python library for automatic tasks in historical linguistics
LICENSE=	gnu-gpl-v3

BROKEN=		Needs py-distribute which conflicts with py-setuptools which is pulled in by dependencies

DEPENDS+=	${PYPKGPREFIX}-networkx>=1.7:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-regex-[0-9]*:../../wip/py-regex

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
