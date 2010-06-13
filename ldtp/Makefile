# $NetBSD: Makefile,v 1.5 2010/06/13 22:47:10 thomasklausner Exp $
#

DISTNAME=	ldtp-2.0.6
PKGREVISION=	1
CATEGORIES=	devel x11 python
MASTER_SITES=	http://download.freedesktop.org/ldtp/2.x/2.0.x/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ldtp.freedesktop.org/wiki/Home
COMMENT=	GNU/Linux Desktop Testing Project
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
REPLACE_PYTHON+=	bin/ldtp

.include "../../devel/py-at-spi/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
