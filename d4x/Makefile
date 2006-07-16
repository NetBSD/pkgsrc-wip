# $NetBSD: Makefile,v 1.9 2006/07/16 16:23:44 shattered Exp $
#

DISTNAME=		d4x-2.5.6
CATEGORIES=		net
MASTER_SITES=		http://www.krasu.ru/soft/chuchelo/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.krasu.ru/soft/chuchelo/
COMMENT=		Download files using a nice GUI

BUILD_DEPENDS+=		bash-[0-9]*:../../shells/bash

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-openssl
CONFIG_SHELL=		${PREFIX}/bin/bash
USE_LANGUAGES+=		c++

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD")
LIBCOMPAT=	-lcompat
.else
LIBCOMPAT=	# none?
.endif

MAKE_ENV+=		LIBOSSAUDIO=${LIBOSSAUDIO:Q} LIBCOMPAT=${LIBCOMPAT:Q}

#include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
