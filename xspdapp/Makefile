# $NetBSD: Makefile,v 1.6 2012/10/07 20:11:10 asau Exp $
#


.include "../../wip/xspd/Makefile.common"
.include "../../wip/xspd/options.mk"

PKGNAME=		xspdapp-${XSPDVERSION}
COMMENT=		Sample C programs for xspd
USE_TOOLS+=		gmake awk echo mkdir cp sed
USE_LANGUAGES=		c
MAKE_ENV+=		CFLAGSX="-march=i386 -m${BITMODE} -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CLDFLAGS="-lcrypt -mpcu=i386 -m${BITMODE}"
MAKE_ENV+=		AWK="awk"
MAKE_ENV+=		AR="ar"
WRKSRC=			${WRKDIR}/${XSPAPP}

# The build dir.
MAKE_ENV+=		TARGETDIR="${WRKSRC}"
# Directory for xspd server
MAKE_ENV+=		PGMROOT="${PREFIX}/bin"
# Directory for xsp program files for xspd
MAKE_ENV+=		XSPROOT="${PREFIX}/share/xspd"
# Directory for xsp config file
MAKE_ENV+=		CONFIGFILE="${PREFIX}/etc/xspd.conf"


post-extract:
	${RM} ${WRKDIR}/xspdinstall ${WRKDIR}/${XSPSYS}_* ${WRKDIR}/xspjava_* ${WRKDIR}/xspjsys_* ${WRKDIR}/xspjsysdoc_* ${WRKDIR}/xspsysdoc_*
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/Readme* ${WRKSRC}/.
	${MV} ${WRKDIR}/*tar ${WRKSRC}/.
	../../mk/extract/extract -d ${WRKSRC} ${WRKSRC}/${XSPAPP}_${XSPAPPID}.tar
	${RM} ${WRKSRC}/${XSPAPP}_${XSPAPPID}.tar

#DEPENDS+=	xspd-${XSPDVERSION}:../../wip/xspd

.include "../../wip/xspd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
