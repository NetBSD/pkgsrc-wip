# $NetBSD: Makefile,v 1.5 2004/04/26 02:28:42 blef Exp $
#

DISTNAME=		kadu-0.3.7
CATEGORIES=		chat
MASTER_SITES=		http://kadu.net/download/stable/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://kadu.net/releases/
COMMENT=		KDE client for polish IM system, called GaduGadu

WRKSRC=			${WRKDIR}/kadu
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
# PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgadu/lib/libgadu.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

# until pkgsrc will be updated with a new of ekg, that provides 
# shared library:
# CONFIGURE_ARGS+=	--with-existing-libgadu
# .include "../../chat/ekg/buildlink2.mk"
CONFLICTS=		ekg-[0-9]*

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
