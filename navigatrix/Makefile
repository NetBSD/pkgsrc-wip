# $NetBSD: Makefile,v 1.2 2003/08/29 10:31:23 thomasklausner Exp $
#

DISTNAME=	navigatrix-0.5
CATEGORIES=	misc
MASTER_SITES=	http://www.maraudingpirates.org/navigatrix/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.maraudingpirates.org/navigatrix/
COMMENT=	GPS navigational system for KDE

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-extra-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-extra-libs=${LOCALBASE}/libs

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../audio/arts/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
