# $NetBSD: Makefile,v 1.6 2013/06/16 09:19:06 noud4 Exp $
#

DISTNAME=	dates-0.4.10
CATEGORIES=	time gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dates/0.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.pimlico-project.org/
COMMENT=	Dates is a small, lightweight calendar
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake

PKGCONFIG_OVERRIDE+=	src/libgtkdatesview.pc.in

CONFIGURE_ARGS+=	--enable-owl

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
