# $NetBSD: Makefile,v 1.10 2012/10/07 16:23:19 asau Exp $

DISTNAME=		symon-2.85
CATEGORIES=		net sysutils
MASTER_SITES=		http://www.xs4all.nl/~wpd/symon/philes/
MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.xs4all.nl/~wpd/symon/
COMMENT=		System monitoring suite

MAKE_ENV+=		RRDDIR=${PREFIX}
MAKE_ENV+=		SYSCONFDIR=${PKG_SYSCONFDIR}

SYMON_HOME?=		${VARBASE}/db/symon
EGDIR=			share/examples/symon
CONF_FILES=		${EGDIR}/symon.conf ${PKG_SYSCONFDIR}/symon.conf
CONF_FILES+=		${EGDIR}/symux.conf ${PKG_SYSCONFDIR}/symux.conf

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

MAKE_DIRS=		${VARBASE}/db
OWN_DIRS=		${SYMON_HOME}
MAKE_DIRS_PERMS+=	${SYMON_HOME} ${SYMON_USER} ${SYMON_GROUP} 0700

INSTALLATION_DIRS+=	libexec ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8 ${EGDIR}

USE_TOOLS+=		perl:run
REPLACE_PERL+=		client/getsymonitem.pl

SYMON_USER?=		_symon
SYMON_GROUP?=		_symon

PKG_GROUPS_VARS+=		SYMON_GROUP
PKG_USERS_VARS+=		SYMON_USER
PKG_GROUPS=			${SYMON_GROUP}
PKG_USERS=			${SYMON_USER}:${SYMON_GROUP}
PKG_GECOS.${SYMON_USER}=	Symon pseudo-user
PKG_HOME.${SYMON_USER}=		${SYMON_HOME}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_FILES.paths=	symon/symon.8 symux/symux.8
SUBST_FILES.paths+=	symux/c_smrrds.sh
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@PKG_PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

RCD_SCRIPTS=		symux symon

FILES_SUBST+=		SYMON_USER=${SYMON_USER:Q}
FILES_SUBST+=		SYMON_GROUP=${SYMON_GROUP:Q}
FILES_SUBST+=		SYMON_HOME=${SYMON_HOME:Q}

# We need to rename the source directory, because it has the same name
# as the symon rc.d script which is copied to WRKDIR
post-extract:
	${MV} ${WRKDIR}/symon ${WRKDIR}/${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/client/getsymonitem.pl \
		${DESTDIR}${PREFIX}/${EGDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/symux/symux \
		${DESTDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/symon/symon \
		${DESTDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/symon/c_config.sh \
		${DESTDIR}${PREFIX}/${EGDIR}/c_config.sh
	${INSTALL_SCRIPT} ${WRKSRC}/symux/c_smrrds.sh \
		${DESTDIR}${PREFIX}/${EGDIR}/c_smrrds.sh
	${INSTALL_DATA} ${WRKSRC}/client/SymuxClient.pm \
		${DESTDIR}${PREFIX}/${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/symon/symon.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/symux/symux.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/
	${INSTALL_MAN} ${WRKSRC}/client/SymuxClient.cat3p \
		${DESTDIR}${PREFIX}/${EGDIR}/SymuxClient.0
	${INSTALL_MAN} ${WRKSRC}/symon/symon.8  \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/symon/symon.cat8  \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/symon.0
	${INSTALL_MAN} ${WRKSRC}/symux/symux.8  \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/symux/symux.cat8  \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/cat8/symux.0

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
