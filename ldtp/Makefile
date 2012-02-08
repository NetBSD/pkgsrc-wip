# $NetBSD: Makefile,v 1.6 2012/02/08 16:54:45 noud4 Exp $
#

DISTNAME=	ldtp-2.0.6
PKGREVISION=	2
CATEGORIES=	devel x11 python
MASTER_SITES=	http://download.freedesktop.org/ldtp/2.x/2.0.x/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ldtp.freedesktop.org/wiki/Home
COMMENT=	GNU/Linux Desktop Testing Project
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-at-spi-[0-9]*:../../devel/py-at-spi

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
REPLACE_PYTHON+=	bin/ldtp

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
