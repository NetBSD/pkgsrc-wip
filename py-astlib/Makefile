# $NetBSD: Makefile,v 1.1 2014/06/20 21:48:08 jihbed Exp $

DISTNAME=	astLib-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	http://cznic.dl.sourceforge.net/project/astlib/astlib/0.7.0/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://astlib.sourceforge.net/
COMMENT=	Set of python modules for producing simple plots, statistics
LICENSE=	gnu-lgpl-v3

PYDISTUTILSPKG=	yes

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=		${PYPKGPREFIX}-scipy>=0.12.0:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
