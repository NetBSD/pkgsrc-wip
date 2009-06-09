# $NetBSD: Makefile,v 1.1.1.1 2009/06/09 22:34:24 othyro Exp $
#

DISTNAME=	pidgin-festival-2.4
CATEGORIES=	chat audio
MASTER_SITES=	http://downloads.sourceforge.net/pidgin-festival/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pidgin-festival.sourceforge.net/
COMMENT=	Pidgin plugin that interfaces with festival

WRKSRC=			${WRKDIR}/pidgin-festival-2.4
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir


.include "../../x11/gtk2/buildlink3.mk"
.include "../../chat/pidgin/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
