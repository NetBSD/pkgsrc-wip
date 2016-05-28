# $NetBSD: Makefile,v 1.17 2012/09/28 21:24:30 asau Exp $
#

DISTNAME=		d4x-2.5.6
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://www.krasu.ru/soft/chuchelo/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.krasu.ru/soft/chuchelo/
COMMENT=		Download files using a nice GUI


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-openssl
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash
CONFIG_SHELL=		${BASH}

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
LIBCOMPAT=	-lcompat
.else
LIBCOMPAT=	# none?
.endif

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO} LIBCOMPAT=${LIBCOMPAT}

#include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
