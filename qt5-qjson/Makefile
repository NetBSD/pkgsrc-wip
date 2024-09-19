# $NetBSD: Makefile,v 1.19 2018/03/12 11:16:20 wiz Exp $

DISTNAME=	qjson-0.9.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=flavio/}
GITHUB_PROJECT=	qjson

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://qjson.sourceforge.net/
COMMENT=	Qt5 library for handling JSON data
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	QJson.pc.in

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	cp ${FILESDIR}/*.* ${WRKSRC}/

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
