# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:27 thomasklausner Exp $
#

DISTNAME=	ldtp-1.6.0
PKGREVISION=	1
CATEGORIES=	devel x11 python
MASTER_SITES=	http://download.freedesktop.org/ldtp/1.x/1.6.x/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ldtp.freedesktop.org/wiki/Home
COMMENT=	GNU/Linux Desktop Testing Project
LICENSE=	gnu-lgpl-v2


PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+= 	--disable-access \
			--enable-goptionparse \
			--enable-newroles

.include "options.mk"

.include "../../devel/libgail-gnome/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
