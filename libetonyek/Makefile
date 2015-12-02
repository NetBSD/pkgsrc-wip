# $NetBSD: Makefile,v 1.10 2015/08/15 22:46:39 wiz Exp $

DISTNAME=	libetonyek-0.1.4
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	https://wiki.documentfoundation.org/DLP/Libraries/libetonyek
COMMENT=	Library for Apple Office suite files
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

# Boost qi.hpp
CXXFLAGS+=	-std=c++0x

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-docs

MDDS_LIBS=/usr/pkg/include
MDDS_CFLAGS+=-I/usr/pkg/include
PKG_CONFIG_PATH=/usr/pkg/include

PKGCONFIG_OVERRIDE+=	libetonyek.pc.in

.include "../../wip/mdds/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/librevenge/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
