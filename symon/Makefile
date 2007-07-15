# $NetBSD: Makefile,v 1.2 2007/07/15 11:04:28 yeled Exp $

DISTNAME=		symon-2.76
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.xs4all.nl/~wpd/symon/philes/

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.xs4all.nl/~wpd/symon/
COMMENT=		system monitor suite

WRKSRC?=        ${WRKDIR}/symon
MAKE_ENV=		LIBS="-Wl,-R${PREFIX}/lib -L${PREFIX}/lib -L../lib"
RRDDIR=${PREFIX} 

SUBST_CLASSES+=                 fix-paths
SUBST_STAGE.fix-paths=          pre-configure
SUBST_MESSAGE.fix-paths=        Fixing absolute paths.
SUBST_FILES.fix-paths+=         Makefile.inc
SUBST_FILES.fix-paths+=         symux/c_smrrds.sh
SUBST_FILES.fix-paths+=         symux/Makefile
SUBST_FILES.fix-paths+=         symon/symon.8
SUBST_FILES.fix-paths+=         symux/symux.8
SUBST_SED.fix-paths=            -e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=           -e 's,/etc,${PREFIX}/etc,g'


#RCD_SCRIPTS=		symon symux
SYMON_USER?=       	_symon
PKG_HOME.symon?=	${VARBASE}/empty
SYMON_GROUP?=      	symon
PKG_GROUPS?=		${SYMON_GROUP}
PKG_USERS?=		${SYMON_USER}:${SYMON_GROUP}:${PKG_HOME.symon}:symon

MAKE_DIRS_PERMS+=       ${VARBASE}/empty ${ROOT_USER} ${ROOT_GROUP} 0700

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
