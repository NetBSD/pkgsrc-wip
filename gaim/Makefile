# $NetBSD: Makefile,v 1.11 2007/01/16 13:14:53 absd Exp $

DISTNAME=	gaim-2.0.0beta5
CATEGORIES=	chat x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gaim/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://gaim.sourceforge.net/
COMMENT=	GTK+ 2.x based multi-protocol instant messaging client

CONFLICTS+=		gaim-gnome-[0-9]*

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

SHLIBTOOL_OVERRIDE+=	libtool

CONFIGURE_ARGS+=	--disable-binreloc
CONFIGURE_ARGS+=	--disable-gevolution
CONFIGURE_ENV+=		DLLIB=${BUILDLINK_LDADD.dl}

# path hackery
SUBST_CLASSES+=			pkg-config
SUBST_STAGE.pkg-config=		post-configure
SUBST_FILES.pkg-config=		config.h
SUBST_SED.pkg-config=		-e "s|PKG_CONFIG=${TOOLS_CMD.pkg-config}|PKG_CONFIG=${TOOLS_PATH.pkg-config}|g"
SUBST_MESSAGE.pkg-config=	Fixing hardcoded PKG_CONFIG path.

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/scrnsaver.h)
CONFIGURE_ARGS+=	--disable-screensaver
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
