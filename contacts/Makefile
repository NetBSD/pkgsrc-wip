# $NetBSD: Makefile,v 1.3 2014/02/11 21:04:08 noud4 Exp $
#

DISTNAME=	contacts-0.12
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/contacts/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	# gone
COMMENT=	Contacts in Gnome using Evolution Database Server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt gmake

CONFIGURE_ARGS+=	--enable-owl

GCONF_SCHEMAS=		contacts.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
