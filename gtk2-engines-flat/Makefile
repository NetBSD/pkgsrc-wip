# $NetBSD: Makefile,v 1.17 2012/09/29 00:50:41 asau Exp $

DISTNAME=		gtk2flat-default
PKGNAME=		gtk2-engines-flat-2.0
WRKSRC=			${WRKDIR}/gtk-flat-theme-2.0
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://freshmeat.net/projects/gtk2flat/url_tgz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freshmeat.net/projects/gtk2flat/
COMMENT=		Flat theme engine for GTK+ 2.x


USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
