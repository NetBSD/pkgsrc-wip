# $NetBSD: Makefile,v 1.2 2008/12/05 10:52:07 thomasklausner Exp $

DISTNAME=	tracker-0.6.6
PKGNAME=	meta-tracker-0.6.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gnome.org/~jamiemcc/tracker/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/tracker/
COMMENT=	Tracker is a tool designed to extract information and metadata

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config gmake perl intltool
USE_LIBTOOL=	YES
USE_LANGUAGES+=	c c++ fortran

CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--enable-low-memory
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
