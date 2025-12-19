# $NetBSD$

DISTNAME=	netdata-2.8.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=netdata/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/netdata/netdata/
COMMENT=	AI-powered full stack observability
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	go-[0-9]*:../../lang/go

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DGO_EXECUTABLE=${GO}
# wants to download corrosion
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NETDATA_JOURNAL_FILE_READER=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PLUGIN_OTEL=OFF
# wants to download dlib
CMAKE_CONFIGURE_ARGS+=	-DENABLE_ML=OFF
# wants to download dashboard
CMAKE_CONFIGURE_ARGS+=	-DENABLE_DASHBOARD=OFF
# needs libipmimonitoring
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PLUGIN_FREEIPMI=OFF

.include "../../devel/cmake/build.mk"
.include "../../lang/go/version.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
