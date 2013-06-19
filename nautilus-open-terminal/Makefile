# $NetBSD: Makefile,v 1.10 2013/06/19 12:12:21 noud4 Exp $
#

DISTNAME=	nautilus-open-terminal-0.18
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/nautilus-open-terminal/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/nautilus-open-terminal/
COMMENT=	Nautilus extension which allows you to open a terminal
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool msgfmt

GCONF_SCHEMAS+=	nautilus-open-terminal.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.nautilus+=	nautilus>=2.12.1nb1
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
