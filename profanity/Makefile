# $NetBSD$

DISTNAME=	profanity-0.5.1
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://www.profanity.im/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.profanity.im/
COMMENT=	Console based XMPP client inspired by irssi
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf

AUTOCONF_REQD=	2.69
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

pre-configure:
		cd ${WRKSRC} && autoconf

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmesode+=	libmesode>=0.9.1
.include "../../wip/libmesode/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../chat/libotr/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
