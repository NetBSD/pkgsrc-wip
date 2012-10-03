# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:54 asau Exp $
#

DISTNAME=		mbpurple-0.3.0
PKGNAME=		${DISTNAME:S|mb|microblog-|}
CATEGORIES=		chat net
MASTER_SITES=		http://microblog-purple.googlecode.com/files/

MAINTAINER=		noud@home.nl
HOMEPAGE=		http://code.google.com/p/microblog-purple/
COMMENT=		Libpurple plug-in supporting microblog services like Twitter
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
BUILD_TARGET=		# empty

INSTALLATION_DIRS+=	lib/purple-2 \
			share/pixmaps/pidgin/protocols/16 \
			share/pixmaps/pidgin/protocols/22 \
			share/pixmaps/pidgin/protocols/48

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
