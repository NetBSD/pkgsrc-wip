# $NetBSD: Makefile,v 1.10 2009/06/09 23:41:05 jihbed Exp $
#

DISTNAME=	ipython-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://ipython.scipy.org/
COMMENT=	Interactive, enhanced Python shell
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline>=0:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-gnuplot>=1.7:../../graphics/py-gnuplot
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.7:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
DEPENDS+=	pydb>=1.26:../../wip/pydb
DEPENDS+=	${PYPKGPREFIX}-foolscap>=0.4.1:../../wip/py-foolscap
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../wip/py-nose
#DEPENDS+=	zope3-[0-9]*:../../www/zope3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

INSTALLATION_DIRS+=	man

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../devel/py-pexpect/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
