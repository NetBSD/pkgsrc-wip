# $NetBSD: Makefile,v 1.1 2005/04/24 19:43:30 martijnb Exp $
#

DISTNAME=		k3b-0.11.23
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=k3b/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://www.k3b.org/
COMMENT=		DVD and CD authoring program

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_GNU_TOOLS+=		make
USE_LIBTOOL=            yes
USE_LANGUAGES=          c c++

AUTOMAKE_REQD=  1.7.9

pre-configure:
	cd ${WRKSRC};                                           \
	${AUTOHEADER};                                          \
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

