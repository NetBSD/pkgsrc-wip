# $NetBSD: Makefile,v 1.6 2014/07/23 10:07:43 obache Exp $
#
DISTNAME=	cde-src-2.2.1
PKGNAME=	${DISTNAME:S/-src-/-/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdesktopenv/}

MAINTAINER=	jelle@jellehermsen.nl
HOMEPAGE=	http://cdesktopenv.sourceforge.net/
COMMENT=	Common Desktop Environment
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=     pkg-config
BUILD_MAKE_FLAGS= World all BOOTSTRAPCFLAGS="-I${X11BASE}/include/X11"

DEPENDS+= bdftopcf-[0-9]*:../../fonts/bdftopcf
DEPENDS+= libiconv-[0-9]*:../../converters/libiconv
DEPENDS+= libXt-[0-9]*:../../x11/libXt
DEPENDS+= libSM-[0-9]*:../../x11/libSM
DEPENDS+= libICE-[0-9]*:../../x11/libICE
DEPENDS+= libXp-[0-9]*:../../x11/libXp

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
