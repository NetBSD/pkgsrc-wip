# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 19:33:01 bmeurer Exp $

DISTNAME=		gtetrinet-0.7.0
PKGNAME=		gtetrinet2-0.7.0
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtetrinet/0.7/}

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://gtetrinet.sourceforge.net/
COMMENT=		Multiplayer tetris game

CONFLICTS+=		gtetrinet-[0-9]*

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
