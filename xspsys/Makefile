# $NetBSD: Makefile,v 1.2 2006/10/24 05:02:04 kcf Exp $
#

.include "../xspd/Makefile.common"

DISTNAME=		${XSPSYS}_${XSPSYSID}
PKGNAME=		${XSPSYS}-${XSPDVERSION}
MASTER_SITES=
EXTRACT_SUFX=		.tar
COMMENT=		http server using C/C++/JAVA/Shell xsp based pages
WRKSRC=			${WRKDIR}
USE_TOOLS+=		gmake awk ar echo mkdir cp
USE_LANGUAGES+=		c
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CLDFLAGS="-lcrypt -mpcu=i386 -m${BITMODE}"

.include "options.mk"

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
