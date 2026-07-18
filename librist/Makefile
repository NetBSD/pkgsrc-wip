# $NetBSD$

DISTNAME=	librist-v0.2.18
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	net
MASTER_SITES=	https://code.videolan.org/rist/librist/-/archive/v0.2.18/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://code.videolan.org/rist/librist/-/archive/v0.2.18/
COMMENT=	Implementation of the RIST protocol
LICENSE=	2-clause-bsd

.include "../../devel/meson/build.mk"

USE_TOOLS=	pkg-config

CFLAGS+=	-Wno-overlength-strings

PKGCONFIG_OVERRIDE+=		output/meson-private/librist.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

post-extract:
	${CP} ${FILESDIR}/tun_netbsd.c ${WRKSRC}/src

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../wip/mbedtls3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
