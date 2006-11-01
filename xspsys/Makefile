# $NetBSD: Makefile,v 1.5 2006/11/01 10:24:45 kcf Exp $
#

.include "../xspd/Makefile.common"

DISTNAME=		${XSPSYS}_${XSPSYSID}
PKGNAME=		${XSPSYS}-${XSPDVERSION}
MASTER_SITES=
EXTRACT_SUFX=		.tar
COMMENT=		http server using C/C++/JAVA/Shell xsp based pages
WRKSRC=			${WRKDIR}
USE_TOOLS+=		gmake awk ar echo mkdir cp sed
USE_LANGUAGES+=		c
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CLDFLAGS="-lcrypt -mpcu=i386 -m${BITMODE}"
# The source dir.
MAKE_ENV+=		PWD="${WRKDIR}"
# The build dir.
MAKE_ENV+=		TARGETDIR="${PREFIX}/bin/xspsys"

.include "options.mk"

BUILD_TARGET=		compile

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
