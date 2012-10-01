# $NetBSD: Makefile,v 1.1 2012/10/01 06:41:28 jellehermsen Exp $
#
# CDE - The Common Desktop Environment
DISTNAME=	cde-2.2.0b
CATEGORIES=	x11

MAINTAINER=	jelle@jellehermsen.nl
HOMEPAGE=	http://cdesktopenv.sourceforge.net/
COMMENT=	CDE is a classic UNIX desktop
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=     pkg-config
.include "../../x11/libX11/buildlink3.mk"
BUILD_MAKE_FLAGS= World all

DEPENDS+= bdftopcf-[0-9]*:../../fonts/bdftopcf
DEPENDS+= libiconv-[0-9]*:../../converters/libiconv
DEPENDS+= libXt-[0-9]*:../../x11/libXt
DEPENDS+= libSM-[0-9]*:../../x11/libSM
DEPENDS+= libICE-[0-9]*:../../x11/libICE
DEPENDS+= libXp-[0-9]*:../../x11/libXp

GIT_REPOSITORIES=   cdesktopenv-code 
GIT_REPO.cdesktopenv-code = git://git.code.sf.net/p/cdesktopenv/code
WRKSRC=$(WRKDIR)/code/cde

PKG_DESTDIR_SUPPORT= user-destdir

.include "../../wip/mk/git-package.mk"
.include "../../mk/motif.buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
