# $NetBSD: Makefile,v 1.7 2012/10/05 11:31:51 asau Exp $
#

DISTNAME=		pidgin-guifications-2.16
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		http://downloads.guifications.org/plugins/Guifications2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://downloads.guifications.org/plugins/Guifications2/
COMMENT=		Toaster notification popups for Pidgin like AIM/MSN/etc

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config intltool

.include "../../chat/pidgin/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
