# $NetBSD: Makefile,v 1.7 2010/06/13 22:47:20 thomasklausner Exp $

DISTNAME=		symon-2.76
PKGREVISION=		2
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.xs4all.nl/~wpd/symon/philes/

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.xs4all.nl/~wpd/symon/
COMMENT=		system monitor suite

WRKSRC?=	${WRKDIR}/symon
MAKE_ENV=		LIBS="-Wl,-R${PREFIX}/lib -L${PREFIX}/lib -L../lib"
RRDDIR=${PREFIX}

MAKE_DIRS_PERMS+=	${SYMON_DIR} ${SYMON_USER} ${SYMON_GROUP} 0700

#RCD_SCRIPTS=		symon symux
SYMON_USER?=		_symon
SYMON_GROUP?=		symon
SYMON_DIR?=	${VARBASE}/db/symon
PKG_GROUPS?=		${SYMON_GROUP}
PKG_USERS?=			${SYMON_USER}:${SYMON_GROUP}::symon

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths+=		Makefile.inc
SUBST_FILES.fix-paths+=		symux/c_smrrds.sh
SUBST_FILES.fix-paths+=		symux/Makefile
SUBST_FILES.fix-paths+=		symon/symon.8
SUBST_FILES.fix-paths+=		symux/symux.8
SUBST_FILES.fix-paths+=		symux/symux.conf
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/etc,${PREFIX}/etc,g'
SUBST_SED.fix-paths+=		-e 's,/var/www/,${VARBASE}/db/,g'

SUBST_CLASSES+=			fix-users
SUBST_STAGE.fix-users=			pre-configure
SUBST_MESSAGE.fix-users=	Fixing hard linked ownerships.
SUBST_FILES.fix-users+=		client/Makefile
SUBST_FILES.fix-users+=		symon/Makefile
SUBST_FILES.fix-users+=		symux/Makefile
SUBST_SED.fix-users+=		-e 's,-o www,${SYMON_USER},g'
SUBST_SED.fix-users+=		-e 's,-g www,${SYMON_GROUP},g'
SUBST_SED.fix-users+=		-e 's,root,${SYMON_USER},g'
SUBST_SED.fix-users+=		-e 's,bin,${SYMON_GROUP},g'
SUBST_SED.fix-users+=		-e 's,wheel,${SYMON_GROUP},g'

FILESDIR=	files
FILES_SUBST+=       SYMON_USER=${SYMON_USER:Q}
FILES_SUBST+=       SYMON_GROUP=${SYMON_GROUP:Q}
FILES_SUBST+=       SYMON_DIR=${SYMON_DIR:Q}
PKG_GROUPS=	${SYMON_GROUP}
PKG_USERS=	${SYMON_USER}:${SYMON_GROUP}
PKG_HOME.${SYMON_USER}= ${SYMON_DIR}


.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
