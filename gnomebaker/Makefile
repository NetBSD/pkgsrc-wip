# $NetBSD: Makefile,v 1.12 2009/03/28 15:40:06 thomasklausner Exp $

DISTNAME=	gnomebaker-0.5.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomebaker/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	http://gnomebaker.sourceforge.net/v2/
COMMENT=	GTK2/GNOME CD/DVD burning application

USE_DIRS+=		xdg-1.4
USE_TOOLS+=		pkg-config msgfmt intltool
GNU_CONFIGURE=		YES

DEPENDS+=	cdrtools>=2.01.01.53:../../sysutils/cdrtools

.include "../../mk/omf-scrollkeeper.mk"
BUILDLINK_API_DEPENDS.libgnomeui+=	libgnomeui>=2.8.1
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
# removed from pkgsrc --  update to newer version!
#.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
