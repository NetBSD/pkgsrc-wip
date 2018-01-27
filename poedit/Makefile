# $NetBSD: Makefile,v 1.54 2015/04/25 14:20:43 tnn Exp $

DISTNAME=	poedit-1.8.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=vslavik/}
GITHUB_RELEASE=	v1.8.6-oss

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.poedit.net/
COMMENT=	Cross-platform gettext catalogs (.po files) editor
LICENSE=	mit

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf automake gmake pkg-config zip:run
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		BDB_TYPE="${BDB_TYPE}"
CONFIGURE_ENV+=		WX_CONFIG_NAME=${BUILDLINK_PREFIX.wxGTK30}/bin/wx-config
CONFIGURE_ARGS+=	--disable-legacytm

MAKE_ENV+=	wxWidgets_CONFIG_EXECUTABLE=${BUILDLINK_PREFIX.wxGTK30}/bin/wx-config


.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/lucene++/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
