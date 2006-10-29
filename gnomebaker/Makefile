# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:43 shattered Exp $

DISTNAME=	gnomebaker-0.5.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomebaker/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leuzi@trash.net
HOMEPAGE=	http://gnomebaker.sourceforge.net/v2/
COMMENT=	GTK2/GNOME CD/DVD burning application

USE_TOOLS+=		pkg-config msgfmt intltool
GNU_CONFIGURE=		YES

DEPENDS+=	cdrtools-ossdvd>=2.0:../../sysutils/cdrtools-ossdvd
DEPENDS+=	libgnomeui>=2.8.1:../../devel/libgnomeui


.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
