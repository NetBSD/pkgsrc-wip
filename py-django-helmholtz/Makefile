# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:14 othyro Exp $
#

DISTNAME=	Helmholtz-0.1.0
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME:S/H/h/}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_PYPI:=H/Helmholtz/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.dbunic.cnrs-gif.fr/helmholtz/
COMMENT=	Framework for creating neuroscience databases
#LICENSE=	cecill

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

WRKSRC=		${WRKDIR}/Helmholtz-0.1.0

USE_TOOLS+=	pax
USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-django-helmholtz

post-install:
	cd ${WRKSRC}/doc && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/py-django-helmholtz

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
