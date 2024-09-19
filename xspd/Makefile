# $NetBSD: Makefile,v 1.13 2012/10/07 20:11:10 asau Exp $
#


.include "Makefile.common"

PKGNAME=		xspd-${XSPDVERSION}
COMMENT=		Http application server
USE_TOOLS+=		gmake awk echo mkdir cp sed
USE_LANGUAGES+=		c
MAKE_ENV+=		CFLAGSX="-march=i386 -m${BITMODE} -g -O -DFD_SETSIZE=1024"
MAKE_ENV+=		CLDFLAGS="-lcrypt -mpcu=i386 -m${BITMODE}"
MAKE_ENV+=		BITMODE="${BITMODE}"
MAKE_ENV+=		AWK="awk"
MAKE_ENV+=		AR="ar"
WRKSRC=			${WRKDIR}/xspsys

# Installation directories
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
LBDIR=			${PREFIX}/lib/${PKGBASE}
INDIR=			${PREFIX}/include/${PKGBASE}
SHDIR=			${PREFIX}/share/${PKGBASE}
UTDIR=			${SHDIR}/utils
BNDIR=			${PREFIX}/bin

# Runtime configuration file subdir, default base is ${PREFIX}/etc, so
#   the full path is ${PREFIX}/etc/${PKG_SYSCONFSUBDIR}
PKG_SYSCONFSUBDIR=	xspd

# The build dir.
MAKE_ENV+=		TARGETDIR="${WRKSRC}"
MAKE_ENV+=		PWD="${WRKSRC}"
# Directory for xspd server
MAKE_ENV+=		INSTALLDIR="${BNDIR}"
# Directory for xsp program files for xspd
MAKE_ENV+=		XSPDIR="${SHDIR}"
# Directory for xsp utility program files for xspd
MAKE_ENV+=		APPUTILDIR="${UTDIR}"
# Runtime xsp config file
MAKE_ENV+=		CONFIGFILE="${PKG_SYSCONFDIR}/xspd.conf"
# Buildtime xsp config file
MAKE_ENV+=		EXAMPLECONFIGFILE="${EGDIR}/xspd.conf"
# Redirect URL
MAKE_ENV+=		REDIRECTURL="http://localhost:80/"

# Buildtime default configuration and runtime destination files
CONF_FILES=		${EGDIR}/xspd.conf ${PKG_SYSCONFDIR}/xspd.conf

# Own Directories
MAKE_DIRS=		${EGDIR}
MAKE_DIRS+=		${LBDIR}
MAKE_DIRS+=		${INDIR}
MAKE_DIRS+=		${SHDIR}
MAKE_DIRS+=		${UTDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}



.include "options.mk"

post-extract:
	${RM} ${WRKDIR}/xspdinstall ${WRKDIR}/xspapp_* ${WRKDIR}/xspjava_* ${WRKDIR}/xspjsys_* ${WRKDIR}/xspjsysdoc_* ${WRKDIR}/xspsysdoc_*
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/Readme* ${WRKSRC}/.
	${MV} ${WRKDIR}/*tar ${WRKSRC}/.
	../../mk/extract/extract -d ${WRKSRC} ${WRKSRC}/xspsys_${XSPSYSID}.tar
	${RM} ${WRKSRC}/xspsys_${XSPSYSID}.tar



.include "../../mk/bsd.pkg.mk"
