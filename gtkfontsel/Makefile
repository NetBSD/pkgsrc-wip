# $NetBSD: Makefile,v 1.4 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=	gtkfontsel_1.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	x11 fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/g/gtkfontsel/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://packages.debian.org/gtkfontsel
COMMENT=	Utility for selecting X11 fonts	to the clipboard


USE_TOOLS=	gmake autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}.orig/ # Debian is strange
USE_LANGUAGES=	c

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
