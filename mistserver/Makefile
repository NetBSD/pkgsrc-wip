# $NetBSD$

DISTNAME=	mistserver-3.10
CATEGORIES=	multimedia www
MASTER_SITES=	${MASTER_SITE_GITHUB:=DDVTECH/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/DDVTECH/mistserver/
COMMENT=	Streaming media toolkit for OTT
LICENSE=	unlicense

.include "../../devel/meson/build.mk"

# MESON_ARGS+=	-DNORIST=true

USE_LANGUAGES=	c c++
USE_TOOLS=	pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../archivers/lz4/buildlink3.mk"
.include "../../comms/srtp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/cJSON/buildlink3.mk"
.include "../../wip/librist/buildlink3.mk"
.include "../../wip/mbedtls3/buildlink3.mk"
.include "../../wip/srt/buildlink3.mk"
.include "../../wip/usrsctp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
