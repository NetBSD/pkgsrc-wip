# $NetBSD: Makefile,v 1.6 2004/07/18 15:25:57 ppostma Exp $
#

DISTNAME=		pango-1.4.0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org
COMMENT=		Development (unstable) version of devel/pango

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/ltmain.sh ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	pango.pc.in
PKGCONFIG_OVERRIDE+=	pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	pangox.pc.in
PKGCONFIG_OVERRIDE+=	pangoxft.pc.in
GNU_CONFIGURE=		yes
USE_X11=		yes

.include "../../wip/glib2-devel/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
