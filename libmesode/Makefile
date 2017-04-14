# $NetBSD$

DISTNAME=	libmesode-0.9.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=boothj5/}
GITHUB_TAG=	e3db0e9bfba61b2d82193874343a94a88f910800

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boothj5/libmesode
COMMENT=	Fork of libstrophe
LICENSE=	mit OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-libxml2

PKGCONFIG_OVERRIDE+=	libmesode.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
