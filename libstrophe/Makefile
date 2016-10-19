# $NetBSD$

DISTNAME=	libstrophe-0.9.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=strophe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://strophe.im/libstrophe/
COMMENT=	Simple, lightweight C library for writing XMPP clients
LICENSE=	mit OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-libxml2

PKGCONFIG_OVERRIDE+=	libstrophe.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
