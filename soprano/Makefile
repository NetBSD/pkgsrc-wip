# $NetBSD: Makefile,v 1.2 2008/07/26 22:17:17 mwdavies Exp $

DISTNAME=	soprano-2.0.99
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soprano/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://soprano.sourceforge.net/
COMMENT=	QT based RDF framework

USE_LANGUAGES=	c c++
#USE_TOOLS+=	gmake pkg-config perl
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	soprano.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../wip/libclucene/buildlink3.mk"
.include "../../wip/redland/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
