# $NetBSD$

DISTNAME=	spectrum2-2.2.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=SpectrumIM/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SpectrumIM/spectrum2/
COMMENT=	Instant Messenger transports
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libtransport/transport.pc.in

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/log4cxx/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
