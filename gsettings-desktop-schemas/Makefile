# $NetBSD: Makefile,v 1.2 2011/10/12 15:46:56 ryo-on Exp $
#

DISTNAME=	gsettings-desktop-schemas-3.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gsettings-desktop-schemas/3.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://launchpad.net/gsettings-desktop-schemas
COMMENT= Contains a collection of GSettings schemas for various components of a desktop
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config intltool msgfmt
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	gsettings-desktop-schemas.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
