# $NetBSD: Makefile,v 1.1 2010/07/26 12:00:43 drochner Exp $
#

DISTNAME=	emerillon-0.1.2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.gnome.org/emerillon/
COMMENT=	Map browser

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://git.gnome.org/emerillon
GIT_TAG=		EMERILLON_0_1_2
.include "../../wip/mk/git-package.mk"

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/emerillon
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake pkg-config intltool gmake msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
CONFIGURE_ARGS+=	--disable-search
GCONF_SCHEMAS=		emerillon.schemas
#PKGCONFIG_OVERRIDE=	data/emerillon.pc.in

# XXX needs manual help
#pre-configure:
#	cd ${WRKSRC} && sh ./autogen.sh

.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../geography/libchamplain06/buildlink3.mk"
.include "../../geography/geoclue/buildlink3.mk"
.include "../../devel/ethos/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
