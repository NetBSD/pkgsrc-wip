# $NetBSD: Makefile,v 1.5 2004/04/25 22:58:16 blef Exp $
#

DISTNAME=	navigatrix-0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.maraudingpirates.org/navigatrix/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.maraudingpirates.org/navigatrix/
COMMENT=	GPS navigational system for KDE

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_X11BASE=		yes

CONFIGURE_ARGS+=	--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-extra-libs=${LOCALBASE}/libs

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
