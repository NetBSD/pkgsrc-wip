# $NetBSD: Makefile,v 1.6 2006/11/15 20:37:11 kcf Exp $
#

.include "Makefile.common"

PKGNAME=		xspd-${XSPDVERSION}
COMMENT=		xspd http application server itself
USE_TOOLS+=		gmake awk ar echo mkdir cp sed
USE_LANGUAGES+=		c
MAKE_ENV+=		CFLAGSX="-march=i386 -m$(BITMODE) -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CLDFLAGS="-lcrypt -mpcu=i386 -m${BITMODE}"
MAKE_ENV+=		AWK="awk"
MAKE_ENV+=		AR="ar"
WRKSRC=			${WRKDIR}/${XSPSYS}

# The build dir.
MAKE_ENV+=		TARGETDIR="${WRKSRC}"
# The install dir.
MAKE_ENV+=		INSTALLDIR="${PREFIX}/bin/xspsys"
# Directory for xspd program
MAKE_ENV+=		PGMROOT="${PREFIX}/bin"
# Directory for xsp program files for xspd
MAKE_ENV+=		XSPROOT="${PREFIX}/share/xspd"



.include "options.mk"

post-extract:
	${RM} ${WRKDIR}/xspdinstall ${WRKDIR}/xspapp_* ${WRKDIR}/xspjava_* ${WRKDIR}/xspjsys_* ${WRKDIR}/xspjsysdoc_* ${WRKDIR}/xspsysdoc_*
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/Readme* ${WRKSRC}/.
	${MV} ${WRKDIR}/*tar ${WRKSRC}/.
	../../mk/extract/extract -d ${WRKSRC} ${WRKSRC}/${XSPSYS}_${XSPSYSID}.tar
	${RM} ${WRKSRC}/${XSPSYS}_${XSPSYSID}.tar



.include "../../mk/bsd.pkg.mk"
