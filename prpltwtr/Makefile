# $NetBSD: Makefile,v 1.1.1.1 2012/01/10 15:56:38 noud4 Exp $
#

DISTNAME=		prpltwtr-0.11.0
CATEGORIES=		chat net
MASTER_SITES=		http://prpltwtr.googlecode.com/files/

MAINTAINER=		noud@home.nl
HOMEPAGE=		http://code.google.com/p/prpltwtr/
COMMENT=		Treat microblogging (Twitter, etc) as IM protocols
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
USE_TOOLS+=		perl
USE_LIBTOOL=		yes
CFLAGS+=		-I${BUILDLINK_DIR}/include/glib/glib-2.0 \
			-I${BUILDLINK_DIR}/lib/glib-2.0/include

PLIST_SUBST+=		DISTNAME=${DISTNAME}
PLIST_SUBST+=		EXTRACT_SUFX=${EXTRACT_SUFX}

INSTALLATION_DIRS+=	lib/pidgin lib/purple-2 \
			share/pixmaps/pidgin/protocols/16 \
			share/pixmaps/pidgin/protocols/22 \
			share/pixmaps/pidgin/protocols/48

.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
