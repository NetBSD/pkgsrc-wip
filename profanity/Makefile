# $NetBSD$

DISTNAME=	profanity-0.8.1
CATEGORIES=	chat
MASTER_SITES=	http://profanity-im.github.io/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://profanity-im.github.io/
COMMENT=	Console based XMPP client inspired by irssi
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf

AUTOCONF_REQD=	2.69
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

# XXX: python-config and python are not properly checked in configure
#CONFIGURE_ARGS+=	--enable-plugins
#CONFIGURE_ARGS+=	--enable-c-plugins
#CONFIGURE_ARGS+=	--enable-python-plugins
#CONFIGURE_ARGS+=	--enable-omemo

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmesode+=	libmesode>=0.9.1
.include "../../wip/libmesode/buildlink3.mk"
#.include "../../wip/libsignal-protocol-c/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../lang/python/application.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
