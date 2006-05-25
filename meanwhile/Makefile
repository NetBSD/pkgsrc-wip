# $NetBSD: Makefile,v 1.1.1.1 2006/05/25 10:51:56 larnor Exp $
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

USE_LANGUAGES+=		c++
USE_LANGUAGES+=		fortran

# path hackery
SUBST_CLASSES+=			pkg_config
SUBST_STAGE.pkg_config=		post-build
SUBST_FILES.pkg_config=		samples/build
SUBST_SED.pkg_config=							\
		-e "s|PKG_CONFIG=${WRKDIR}/.tools|PKG_CONFIG=${LOCALBASE}|g"
SUBST_MESSAGE.pkg_config=	Fixing hardcoded PKG_CONFIG path

.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
