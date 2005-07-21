# $NetBSD: Makefile,v 1.6 2005/07/21 16:34:01 thomasklausner Exp $
#

DISTNAME=		kazehakase-0.2.8
CATEGORIES=		www
MASTER_SITES=		http://osdn.dl.sourceforge.jp/kazehakase/15343/ \
			http://keihanna.dl.sourceforge.jp/kazehakase/15343/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://kazehakase.sourceforge.jp/
COMMENT=		Web browser with multiple layout engines support

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.kazehakase
.include "../../www/mozilla/gecko-options.mk"
.include "../../mk/bsd.options.mk"

PKG_SYSCONFSUBDIR=	kazehakase
EGDIR=		${PREFIX}/share/examples/kazehakase
EGFILES=	bookmarkbar.xml bookmarks.xml kz-ui-beginner.xml	\
		kz-ui-bookmarks.xml kz-ui-expert.xml kz-ui-medium.xml	\
		kzrc proxyrc smartbookmarks.xml
.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

MAKE_DIRS+=	${PKG_SYSCONFDIR}/mozilla
CONF_FILES+=	${EGDIR}/mozilla/encodings.xml ${PKG_SYSCONFDIR}/mozilla/encodings.xml

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../www/mozilla/gecko-depends.mk"
.include "../../mk/bsd.pkg.mk"
