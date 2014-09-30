# $NetBSD: Makefile,v 1.1 2014/09/30 00:38:19 makoto Exp $

DISTNAME=		libmirisdr-0.1
CATEGORIES=		ham

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sdr.osmocom.org/trac/wiki/GrOsmoSDR
COMMENT=		Osmocom Mirics MSi2500 + MSi001 SDR library
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=       master
GIT_REPO.master=        http://cgit.osmocom.org/libmirisdr/
GIT_MODULE.master=	libmirisdr

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake
USE_CMAKE=		yes

WRKSRC=			${WRKDIR}/libmirisdr

# Supress warning for developer
CMAKE_ARGS+=	-Wno-dev

.include "../../wip/mk/git-package.mk"
# you need place after above line for now.
_GIT_FLAGS=		# set empty, --depth 1 seems harmfull

.include	"../../devel/libusb1/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
