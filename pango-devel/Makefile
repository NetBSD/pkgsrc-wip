# $NetBSD: Makefile,v 1.4 2004/03/17 13:22:30 mpasternak Exp $
#

DISTNAME=		pango-1.4.0
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org
COMMENT=		Development (unstable) version of devel/pango

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/ltmain.sh ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pango.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangox.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoxft.pc.in
GNU_CONFIGURE=		yes
USE_X11=		yes

.include "../../wip/glib2-devel/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
