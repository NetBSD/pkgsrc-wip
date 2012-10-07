# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	rubrica2-2.1.6
CATEGORIES=	misc
MASTER_SITES=	http://sourceforge.net/projects/rubrica.berlios/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubrica.berlios.de/
COMMENT=	Addressbook manager for the GNOME Environment
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gconftool-2 gmake msgfmt msgmerge perl pkg-config
USE_TOOLS+=		xgettext
USE_PKGLOCALEDIR=	yes

USE_LANGUAGES+=		c c++ fortran

GCONF_SCHEMAS+=		rubrica2.schemas
PKGCONFIG_OVERRIDE+=	libral/libral.pc.in
CONFIGURE_ARGS+=	--with-gconf-source=${PREFIX}/share/gconf/schemas
CONFIGURE_ARGS+=	--with-gconf-schema-file-dir=${PREFIX}/share/gconf/schemas

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/bsd.pkg.mk"
