# $NetBSD: Makefile,v 1.2 2004/02/17 02:56:31 blef Exp $
#

DISTNAME=		pango-1.3.1
PKGNAME=		pango-devel-1.3.1
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.3/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gtk.org
COMMENT=		Development (unstable) version of devel/pango

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pango.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangox.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoxft.pc.in
GNU_CONFIGURE=		yes
USE_X11=		yes

CONFLICTS=		pango-[*]

.include "../../wip/glib2-devel/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
