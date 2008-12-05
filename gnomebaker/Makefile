# $NetBSD: Makefile,v 1.9 2008/12/05 22:50:48 tnn2 Exp $

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
DEPENDS+=	libgnomeui>=2.8.1:../../devel/libgnomeui


.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
