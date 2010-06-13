# $NetBSD: Makefile,v 1.2 2010/06/13 22:46:58 thomasklausner Exp $
#

DISTNAME=	dates-0.4.8
PKGREVISION=	1
CATEGORIES=	time gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/dates/0.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.pimlico-project.org/
COMMENT=	Dates is a small, lightweight calenda
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

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
