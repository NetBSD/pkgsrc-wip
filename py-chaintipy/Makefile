# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:25 asau Exp $

DISTNAME=	ChiantiPy-0.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/C/c/S/P/p/S/.tar//}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=C/ChiantiPy/}
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/chiantipy
COMMENT=	CHIANTI atomic database for astrophysical spectroscopy
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

WRKSRC=		${WRKDIR}/ChiantiPy-0.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "options.mk"

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
