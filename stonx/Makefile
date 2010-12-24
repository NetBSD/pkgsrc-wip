# $NetBSD: Makefile,v 1.6 2010/12/24 18:07:11 noud4 Exp $
#

DISTNAME=		STonX-0.6.7.6
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stonx/}

MAINTAINER=		xmor61@users.sourceforge.net
HOMEPAGE=		http://stonx.sourceforge.net/
COMMENT=		Atari ST Emulator

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"
.if ${X11_TYPE} == "modular"
.include "../../x11/libXext/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
