# $NetBSD: Makefile,v 1.7 2006/11/16 05:02:46 kcf Exp $
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
# Directory for xspd server
MAKE_ENV+=		PGMROOT="${PREFIX}/bin"
# Directory for xsp program files for xspd
MAKE_ENV+=		XSPROOT="${PREFIX}/share/xspd"
# Directory for xsp config file
MAKE_ENV+=		CONFIGFILE="${PREFIX}/etc/xspd.conf"
# Redirect URL
MAKE_ENV+=		REDIRECTURL="http://localhost:80/"



.include "options.mk"

post-extract:
	${RM} ${WRKDIR}/xspdinstall ${WRKDIR}/xspapp_* ${WRKDIR}/xspjava_* ${WRKDIR}/xspjsys_* ${WRKDIR}/xspjsysdoc_* ${WRKDIR}/xspsysdoc_*
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/Readme* ${WRKSRC}/.
	${MV} ${WRKDIR}/*tar ${WRKSRC}/.
	../../mk/extract/extract -d ${WRKSRC} ${WRKSRC}/${XSPSYS}_${XSPSYSID}.tar
	${RM} ${WRKSRC}/${XSPSYS}_${XSPSYSID}.tar



.include "../../mk/bsd.pkg.mk"
