# $NetBSD: Makefile,v 1.20 2019/04/09 00:21:03 gdt Exp $
#

DISTNAME=	gpsbabel-1.5.4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_LOCAL}
# Download from official site apparently only via interactive form,
# but code is gnu-gpl-v2 so hosted elsewhere.
# older versions were at
# MASTER_SITES+=	http://archlinux-stuff.googlecode.com/files/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.gpsbabel.org/
#HOMEPAGE=	https://github.com/gpsbabel/gpsbabel
COMMENT=	Utility to convert and fetch GPS related data
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++11

TEST_TARGET=	check

LIBS.Darwin+=	-lexpat

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	QMAKE=${QTDIR}/bin/qmake
CONFIGURE_ENV+=	LUPDATE=${QTDIR}/bin/lupdate
CONFIGURE_ENV+=	LRELEASE=${QTDIR}/bin/lrelease

.include "../../mk/libusb.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
