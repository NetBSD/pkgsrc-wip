# $NetBSD: Makefile,v 1.3 2006/08/10 12:38:49 absd Exp $
#

DISTNAME=		meanwhile-1.0.2
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=meanwhile/}

MAINTAINER=		lars.nordlund@hem.utfors.se
HOMEPAGE=		http://meanwhile.sourceforge.net/
COMMENT=		The Lotus Sametime Community Client protocol

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-doxygen=no

PKGCONFIG_OVERRIDE+=	meanwhile.pc.in

USE_LANGUAGES+=		c
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		fortran

# path hackery
SUBST_CLASSES+=			pkg-config
SUBST_STAGE.pkg-config=		post-build
SUBST_FILES.pkg-config=		samples/build
SUBST_SED.pkg-config=		-e "s|PKG_CONFIG=${TOOLS_CMD.pkg-config}|PKG_CONFIG=${TOOLS_PATH.pkg-config}|g"
SUBST_MESSAGE.pkg-config=	Fixing hardcoded PKG_CONFIG path

.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
