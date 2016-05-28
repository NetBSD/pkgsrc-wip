# $NetBSD: Makefile,v 1.6 2012/10/07 16:23:21 asau Exp $
#

DISTNAME=		synce-kde-0.9.1
PKGREVISION=		3
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.synce.org/oldwiki/index.php/KDE
COMMENT=		Integrate Windows CE or Windows Mobile device into KDE


USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-librra=${PREFIX}
#ONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde

.include "../../mk/jpeg.buildlink3.mk"
.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../comms/synce-rra/buildlink3.mk"
.include "../../wip/synce-orange/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
