# $NetBSD: Makefile,v 1.1.1.1 2003/11/29 21:52:55 mpasternak Exp $
#

DISTNAME=		kadu-0.3.6
CATEGORIES=		chat
MASTER_SITES=		http://kadu.net/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://kadu.net/releases/
COMMENT=		KDE client for polish IM system, called GaduGadu

WRKSRC=			${WRKDIR}/kadu
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
# PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgadu/lib/libgadu.pc.in
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ARGS+=	--with-existing-libgadu

.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../chat/ekg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
