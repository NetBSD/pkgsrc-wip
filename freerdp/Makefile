# $NetBSD: Makefile,v 1.35 2018/11/14 22:22:10 kleink Exp $

DISTNAME=	freerdp-2.0.0-rc4
PKGNAME=	${DISTNAME:S/-rc/rc/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=FreeRDP/}
GITHUB_PROJECT=	FreeRDP
GITHUB_TAG=	${PKGVERSION_NOREV:S/rc/-rc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freerdp.com/
COMMENT=	Free implementation of the Remote Desktop Protocol
LICENSE=	apache-2.0

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
#USE_OLD_DES_API=	yes
CMAKE_ARGS+=		-DWITH_WAYLAND=OFF

PKGCONFIG_OVERRIDE+=	freerdp.pc.in

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
