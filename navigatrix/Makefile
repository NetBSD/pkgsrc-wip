# $NetBSD: Makefile,v 1.6 2004/08/17 18:31:25 tvierling Exp $
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
LIBTOOL_LA_FILES+=	lib/libgis.la
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
