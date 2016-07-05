# $NetBSD: Makefile,v 1.3 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	opencascade-7.0.0
CATEGORIES=	cad
# Official webpage requires login
MASTER_SITES=	https://sources.archlinux.org/other/community/opencascade/
EXTRACT_SUFX=	.tgz

MAINTAINER=	silasdb@gmail.com
HOMEPAGE=	http://www.opencascade.org/
COMMENT=	Software development platform for 3D CAD CAM CAE
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	bash
USE_LANGUAGES=	c c++

REPLACE_BASH+=	adm/templates/*
REPLACE_BASH+=	*

CHECK_PORTABILITY_SKIP+=	samples/qt/*

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl
BUILDLINK_TRANSFORM+=		opt:-std=c++0x:-std=gnu++11

# HACK
post-install:
	${RUN} chmod go-w ${DESTDIR}${PREFIX}/bin/*
	${RUN} rm -f ${DESTDIR}${PREFIX}/share/opencascade/resources/DrawResources/InitEnvironment.tcl.orig

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
