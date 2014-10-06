# $NetBSD: Makefile,v 1.6 2014/10/06 12:54:15 makoto Exp $

DISTNAME=	libmirisdr-master
PKGNAME=	libmirisdr-0.1
CATEGORIES=	ham

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.osmocom.org/libmirisdr/
COMMENT=	Osmocom Mirics MSi2500 + MSi001 SDR library
LICENSE=	gnu-gpl-v2
MASTER_SITES+=	http://cgit.osmocom.org/libmirisdr/snapshot/
DIST_SUBDIR=	${PKGBASE}-2013-06-08

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS=	cmake pkg-config
USE_CMAKE=	yes

# Supress warning for developer
CMAKE_ARGS+=	-Wno-dev

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
