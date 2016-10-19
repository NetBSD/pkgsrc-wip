# $NetBSD$

DISTNAME=	profanity-0.5.0
CATEGORIES=	chat
MASTER_SITES=	http://www.profanity.im/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.profanity.im/
COMMENT=	Console based XMPP client inspired by irssi
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-libxml2

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.libstrophe+=	libstrophe>=0.9.1
.include "../../wip/libstrophe/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
