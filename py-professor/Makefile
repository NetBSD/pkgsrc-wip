# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:05:40 jihbed Exp $
#

DISTNAME=	professor-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	physics python
MASTER_SITES=	http://www.hepforge.org/archive/professor/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/professor/
COMMENT=	Parameterisation-based tuning tool for Monte Carlo event generators
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=1.0.1
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
