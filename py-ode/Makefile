# $NetBSD: Makefile,v 1.1 2015/08/05 20:45:10 jihbed Exp $

DISTNAME=	PyODE-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyODE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyode.sourceforge.net/
COMMENT=	Python wrapper for the Open Dynamics Engine
LICENSE=	modified-bsd OR gnu-lgpl-2.1

PYDISTUTILSPKG= yes

.include "../../devel/ode/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
