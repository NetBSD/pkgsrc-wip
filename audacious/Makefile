# $NetBSD: Makefile,v 1.2 2007/02/01 10:17:36 lkundrak Exp $
#

DISTNAME=		audacious-1.2.2
CATEGORIES=		audio
MASTER_SITES=		http://audacious-media-player.org/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		http://audacious-media-player.org/
COMMENT=        	Media player based on BMP and XMMS

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_LIBTOOL=    	yes
USE_LANGUAGES+= 	c c++

CONFIGURE_ARGS+=        --enable-chardet --enable-nls

PKGCONFIG_OVERRIDE+=	audacious.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../wip/alsa-lib/buildlink3.mk"
.endif

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
