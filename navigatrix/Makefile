# $NetBSD: Makefile,v 1.18 2012/10/03 18:15:31 asau Exp $
#

DISTNAME=	navigatrix-0.5
PKGREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	http://www1.maraudingpirates.org:8080/navigatrix/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www1.maraudingpirates.org:8080/navigatrix/
COMMENT=	GPS navigational system for KDE


GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_X11BASE=		yes

CONFIGURE_ARGS+=	--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-extra-libs=${LOCALBASE}/libs

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
