# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:44:59 jihbed Exp $
#

DISTNAME=	ChiantiPy-0.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/C/c/S/P/p/S/.tar//}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/C/ChiantiPy/
EXTRACT_SUFX=	.gz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://sourceforge.net/projects/chiantipy
COMMENT=	CHIANTI atomic database for astrophysical spectroscopy
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ChiantiPy-0.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "options.mk"

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
