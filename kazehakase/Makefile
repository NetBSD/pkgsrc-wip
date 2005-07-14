# $NetBSD: Makefile,v 1.3 2005/07/14 22:10:04 leonardschmidt Exp $
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
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if ${GECKO_PROVIDER} == "firefox"
.include "../../www/firefox/buildlink3.mk"
.else
.include "../../www/mozilla-gtk2/buildlink3.mk"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
