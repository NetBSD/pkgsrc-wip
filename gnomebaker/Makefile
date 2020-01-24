# $NetBSD: Makefile,v 1.20 2013/11/07 09:01:13 noud4 Exp $

DISTNAME=	gnomebaker-0.6.4
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomebaker/}
LICENSE=	gnu-gpl-v2

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	http://gnomebaker.sourceforge.net/v2/
COMMENT=	GTK2/GNOME CD/DVD burning application

DEPENDS+=	cdrtools>=2.01:../../sysutils/cdrtools

USE_TOOLS+=		pkg-config msgfmt intltool
GNU_CONFIGURE=		YES


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.8.1
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
