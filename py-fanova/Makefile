# $NetBSD: Makefile,v 1.1 2014/06/21 18:26:15 jihbed Exp $

DISTNAME=	pyfanova-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S//py/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyfanova/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/automl/fanova
COMMENT=	Functional ANOVA
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

PKG_JVMS_ACCEPTED=	sun-jdk7 sun-jdk6 sun-jdk15 sun-jdk14

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
