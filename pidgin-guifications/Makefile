# $NetBSD: Makefile,v 1.3 2007/11/13 19:47:59 briandealwis Exp $
#

DISTNAME=		pidgin-guifications-2.14
CATEGORIES=		chat
MASTER_SITES=		http://downloads.guifications.org/plugins/Guifications2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://downloads.guifications.org/plugins/Guifications2/
COMMENT=		Toaster notification popups for Pidgin like AIM/MSN/etc

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config intltool
USE_LIBTOOL=		yes
USE_X11=                YES

.include "../../chat/pidgin/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
