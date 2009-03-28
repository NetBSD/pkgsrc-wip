# $NetBSD: Makefile,v 1.14 2009/03/28 18:04:08 thomasklausner Exp $

DISTNAME=	gnomebaker-0.6.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomebaker/}

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	http://gnomebaker.sourceforge.net/v2/
COMMENT=	GTK2/GNOME CD/DVD burning application

DEPENDS+=	cdrtools>=2.01:../../sysutils/cdrtools

USE_DIRS+=		xdg-1.4 gnome2-1.4
USE_TOOLS+=		pkg-config msgfmt intltool
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.8.1
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
