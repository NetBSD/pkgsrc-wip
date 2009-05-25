# $NetBSD: Makefile,v 1.1.1.1 2009/05/25 15:26:09 jihbed Exp $
#

DISTNAME=	ldtp-1.5.1
CATEGORIES=	devel x11 python
MASTER_SITES=	http://download.freedesktop.org/ldtp/1.x/1.5.x/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://ldtp.freedesktop.org/wiki/Home
COMMENT=	GNU/Linux Desktop Testing Project

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake

CONFIGURE_ARGS+= 			\
		--enable-goptionparse    \
		--enable-newroles	\
		--disable-access	\
		--without-pythonmodules

CONFIGURE_ARGS+=	--disable-localization

.include "options.mk"

.include "../../devel/libgail-gnome/buildlink3.mk"
.include "../../devel/py-at-spi/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/py-ORBit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"

.include "../../lang/python/pyversion.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
