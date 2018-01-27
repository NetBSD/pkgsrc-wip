# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:48 thomasklausner Exp $

VERSION=	1.0.9
DISTNAME=	Kivy-1.0.9
PKGNAME=	${PYPKGPREFIX}-kivy-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kivy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://kivy.org/#home
COMMENT=	Innovative user interfaces made easy
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.6.5:../../textproc/py-enchant

USE_LANGUAGES=	c

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-imaging, py-gstreamer0.10, py-gobject

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../multimedia/py-gstreamer0.10/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
