# $NetBSD: Makefile,v 1.4 2012/02/01 13:41:02 jihbed Exp $
#

VERSION=	1.0.9
DISTNAME=	Kivy-1.0.9
PKGNAME=   	${PYPKGPREFIX}-kivy-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/K/Kivy/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://kivy.org/#home
COMMENT=	Innovative user interfaces made easy
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-multiprocessing>=2.6.2.1:../../devel/py-multiprocessing
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.6.5:../../textproc/py-enchant

# py-ctypes is included in Python 2.5 and higher (Thank you ndb)
#DEPENDS+=	${PYPKGPREFIX}-ctypes>=1.0.2:../../devel/py-ctypes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES= c

PYTHON_VERSIONS_ACCEPTED= 27 26
PYDISTUTILSPKG=		yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
