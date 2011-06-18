# $NetBSD: Makefile,v 1.9 2011/06/18 13:52:07 obache Exp $

.include "../../wip/ja-freewnn-lib/Makefile.common"

PKGNAME=	ja-FreeWnn-server-1.11alpha22

COMMENT+=	(Japanese server)

CONFIGURE_ARGS+=	--disable-libraries
# Following two lines gives equivalent to previous 1.10 version
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

CONFIGURE_ARGS+=	--with-wnn-libraries=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/lib
CONFIGURE_ARGS+=	--with-libwnn=yes
CONFIGURE_ARGS+=	--disable-sub-bindir
# use sbin/ instead of bin/
CONFIGURE_ARGS+=	--disable-traditional-layout

INSTALL_TARGET=	install install.man

RCD_SCRIPTS=    ja_freewnn

BUILD_DEFS=	FREEWNN_USER FREEWNN_GROUP

FREEWNN_USER=	wnn
FREEWNN_GROUP=	jserver
PKG_GROUPS=	${FREEWNN_GROUP}
PKG_USERS=	${FREEWNN_USER}:${FREEWNN_GROUP}

SPECIAL_PERMS+=	bin/Wnn4/jserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4511
SPECIAL_PERMS+=	bin/Wnn4/cserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4511
SPECIAL_PERMS+=	bin/Wnn4/tserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4511
SPECIAL_PERMS+=	bin/Wnn4/kserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4511

OWN_DIRS+=		${IMDICTDIR}/wnn/ja_JP
OWN_DIRS_PERMS+=	${IMDICTDIR}/wnn/ja_JP/usr ${FREEWNN_USER} ${FREEWNN_GROUP} ${PKGDIRMODE}

.include "../../wip/ja-freewnn-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
