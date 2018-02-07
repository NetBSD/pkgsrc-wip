# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:15 othyro Exp $

DISTNAME=	professor-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	http://www.hepforge.org/archive/professor/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/professor/
COMMENT=	Parameterisation-based tuning tool for Monte Carlo event generators
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
