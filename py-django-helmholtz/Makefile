# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:25 asau Exp $
#

DISTNAME=	Helmholtz-0.1.0
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME:S/H/h/}
CATEGORIES=	science  python
MASTER_SITES=	http://pypi.python.org/packages/source/H/Helmholtz/

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
