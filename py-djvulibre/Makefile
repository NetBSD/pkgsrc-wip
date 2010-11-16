# $NetBSD: Makefile,v 1.2 2010/11/16 13:11:26 ryo-on Exp $
#
DISTNAME=	python-djvulibre-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	graphics textproc
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-djvulibre/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://jwilk.net/software/python-djvulibre
COMMENT=	Python bindings for the DjVuLibre library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-pyrex-[0-9]*:../../lang/py-pyrex
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c

PYTHON_VERSIONS_ACCEPTED=	26 25
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
