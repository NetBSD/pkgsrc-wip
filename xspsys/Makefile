# $NetBSD: Makefile,v 1.6 2006/11/06 05:47:36 kcf Exp $
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
# The build dir.
MAKE_ENV+=		TARGETDIR="${WRKDIR}"
# The install dir.
MAKE_ENV+=		INSTALLDIR="${PREFIX}/bin/xspsys"

.include "options.mk"

#BUILD_TARGET=		compile

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
