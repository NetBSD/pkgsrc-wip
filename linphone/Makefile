# $NetBSD: Makefile,v 1.21 2008/11/20 17:35:47 thomasklausner Exp $

DISTNAME=	linphone-2.1.1
CATEGORIES=	net
MASTER_SITES=	http://download.savannah.gnu.org/releases/linphone/stable/sources/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.linphone.org/
COMMENT=	SIP-based IP telephony client

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake intltool perl pkg-config
USE_DIRS+=	gnome2-1.6 xdg-1.4
USE_LIBTOOL=	YES
USE_GNU_READLINE=	yes # rl_hook_func_t et al.
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--with-osip=${BUILDLINK_PREFIX.libosip2}
CONFIGURE_ARGS+=	--with-speex=${BUILDLINK_PREFIX.speex}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/linphone
CONFIGURE_ARGS+=	--disable-manual --enable-glib

.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--enable-macsnd
. if !empty(PKGSRC_COMPILER:Mgcc*)
SUBST_CLASSES+=			objective-c
SUBST_STAGE.objective-c=	post-patch
SUBST_MESSAGE.objective-c=	adding "-x objective-c" for mediastreamer2 code
SUBST_FILES.objective-c=	mediastreamer2/src/Makefile.in
SUBST_SED.objective-c=		-e 's/^CC = @CC@/CC = @CC@ -x objective-c/g'
. endif
.else # OS other than MacOS X
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDSP_NAME="\"${DEVOSSAUDIO}\""
.include "../../mk/oss.buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libosip/buildlink3.mk"
.include "../../wip/libexosip/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
