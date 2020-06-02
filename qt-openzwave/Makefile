# $NetBSD$

# Upstream does not have releases, and does not even have tags.
# Create a faux version that will always increase, by date, and .N if
# necessary.
GITHUB_TAG=	96d896d2ad3955e2d42bc58fa5595046fb36c907
VERSION=	20200602.0
DISTNAME=	qt-openzwave-${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=openzwave/}
CATEGORIES=	comms
MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OpenZWave/qt-openzwave
COMMENT=	Daemon and MQTT interface for Z-Wave controller
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

# install?

.include "../../wip/openzwave/buildlink3.mk"

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebsockets/buildlink3.mk"

# libunwind
# curl
# qt5-default
# qtbase5-private
# qt5 remoteobjects TODO
.include "../../textproc/rapidjson/buildlink3.mk"

#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
