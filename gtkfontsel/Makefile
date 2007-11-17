# $NetBSD: Makefile,v 1.3 2007/11/17 14:41:57 netcap Exp $
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
