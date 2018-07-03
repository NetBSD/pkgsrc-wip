# $NetBSD: Makefile,v 1.9 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	ldtp-2.0.6
PKGREVISION=	2
CATEGORIES=	devel x11 python
MASTER_SITES=	http://download.freedesktop.org/ldtp/2.x/2.0.x/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://ldtp.freedesktop.org/wiki/
COMMENT=	GNU/Linux Desktop Testing Project
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-at-spi-[0-9]*:../../devel/py-at-spi

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		bin/ldtp
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit and py-gnome2 via py-at-spi, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
