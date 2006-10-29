# $NetBSD: Makefile,v 1.4 2006/10/29 08:32:58 shattered Exp $
#

.include "../xspd/Makefile.common"

DISTNAME=		${XSPSYS}_${XSPSYSID}
PKGNAME=		${XSPSYS}-${XSPDVERSION}
MASTER_SITES=
EXTRACT_SUFX=		.tar
COMMENT=		http server using C/C++/JAVA/Shell xsp based pages
WRKSRC=			${WRKDIR}
USE_TOOLS+=		gmake awk ar echo mkdir cp sed
USE_LANGUAGES=		c
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CLDFLAGS="-lcrypt -mpcu=i386 -m${BITMODE}"

.include "options.mk"

pre-configure:
	${MKDIR} work/lib
	${MKDIR} work/obj
	${MKDIR} work/tmpdir

do-install:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
