# $NetBSD: Makefile,v 1.14 2004/04/07 06:58:45 bubuchka Exp $
#
# Note: We'll not use drweb's own configuration / building / installation
# facilities so as its all are very ugly.

DISTNAME=	drweb-4.31.3-${DISTTYPE}
PKGNAME=	drweb-4.31.3
CATEGORIES=	wip security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/				\
		ftp://ftp.drweb.ru/pub/unix/betas/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sald.com/
COMMENT=	DrWeb Antivirus Suite

ONLY_FOR_PLATFORM= FreeBSD-[3-5].[0-9]*-i386 OpenBSD-[3-9].*-i386	\
		NetBSD-1.[6-9]*-i386 NetBSD-[2-9].[0-9]-i386		\
		Linux-*-i[3-6]86 Solaris-*-i386

.include "../../wip/mk/rcd.mk"

.if   ${OPSYS} == "FreeBSD" && ${MAJOR_OS_VERSION} >= 5.0
DISTTYPE=	freebsd5
.elif ${OPSYS} == "FreeBSD" && ${MAJOR_OS_VERSION} >= 4.0
DISTTYPE=	freebsd4
.elif ${OPSYS} == "FreeBSD" && ${MAJOR_OS_VERSION} >= 3.0
DISTTYPE=	freebsd3
.elif ${OPSYS} == "OpenBSD" && ${MAJOR_OS_VERSION} >= 3.4
DISTTYPE=	openbsd34
.elif ${OPSYS} == "OpenBSD" && ${MAJOR_OS_VERSION} >= 3.0
DISTTYPE=	openbsd3
.elif ${OPSYS} == "NetBSD"
DISTTYPE=	freebsd4
.elif ${OPSYS} == "Solaris"
DISTTYPE=	solaris
.elif ${OPSYS} == "Linux"
GLIBC_VERSION?=	2.3
BUILD_DEFS+=	GLIBC_VERSION
DISTTYPE=	glibc.${GLIBC_VERSION}
.endif

# The following used by drweb-update script only
.if ${OPSYS} != "FreeBSD"	# FreeBSD have a fetch(1)
DEPENDS=	wget>=1.7:../../net/wget
.endif
USE_PERL5=	YES

NO_BUILD=	YES

BUILD_DEFS+=	DRW_DIR	DRW_BASESDIR DRW_INFECTDIR			\
		DRW_LOGDIR DRW_RUNDIR					\
		DRW_PIDFILE DRW_SOCKFILE

PKG_GROUPS=	${DRW_GROUP}
PKG_USERS=	${DRW_USER}:${PKG_GROUPS}::DrWeb\\ AntiVirus

OWN_DIRS_PERMS=	${DRW_DIR} ${DRW_USER} ${DRW_GROUP} 0755		\
		${DRW_BASESDIR} ${DRW_USER} ${DRW_GROUP} 0755		\
		${DRW_INFECTDIR} ${DRW_USER} ${DRW_GROUP} 0700		\
		${DRW_LOGDIR} ${DRW_USER} ${DRW_GROUP} 0755		\
		${DRW_RUNDIR} ${DRW_USER} ${DRW_GROUP} 0755

CONF_FILES=	${EGDIR}/drweb32.ini ${PKG_SYSCONFDIR}/drweb32.ini
SUPPORT_FILES=	${EGDIR}/drweb.key ${PKG_SYSCONFDIR}/drweb.key		\
		${EGDIR}/drwebd.key ${PKG_SYSCONFDIR}/drwebd.key	\
		${EGDIR}/drweb32.dll ${DRW_BASESDIR}/drweb32.dll	\
		${EGDIR}/drwebase.vdb ${DRW_BASESDIR}/drwebase.vdb	\
		${EGDIR}/drw43101.vdb ${DRW_BASESDIR}/drw43101.vdb

RCD_SCRIPTS=		drwebd
RCD_SCRIPT_SRC.drwebd=	${FILESDIR}/drwebd-rcd.src

.if ${OPSYS:C/^.*BSD.*$/BSD/} == "BSD"
WRKSRC_BIN=	${WRKSRC}/usr/local/drweb
WRKSRC_INI=	${WRKSRC}/usr/local/etc/drweb
.else
WRKSRC_BIN=	${WRKSRC}/opt/drweb
WRKSRC_INI=	${WRKSRC}/etc/drweb
.endif

post-patch:
	@${PATCH} ${WRKSRC_INI}/drweb32.ini < ${FILESDIR}/drweb32-ini.patch

do-configure:
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drweb-sh.src > ${WRKDIR}/drweb-sh
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drwebd-sh.src > ${WRKDIR}/drwebd-sh
	@${SED} ${FILES_SUBST_SED}					\
		${WRKSRC_BIN}/update/update.pl > ${WRKDIR}/drweb-update
	@${SED} ${FILES_SUBST_SED}					\
		${WRKSRC_INI}/drweb32.ini > ${WRKDIR}/drweb32-ini
.if ${OPSYS} == "NetBSD"
	${MV} ${WRKSRC_BIN}/drweb.static ${WRKDIR}/drweb-bin
	${MV} ${WRKSRC_BIN}/drwebd.static ${WRKDIR}/drwebd-bin
.else
	${MV} ${WRKSRC_BIN}/drweb ${WRKDIR}/drweb-bin
	${MV} ${WRKSRC_BIN}/drwebd ${WRKDIR}/drwebd-bin
.endif

do-install:
	# --> Executables
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-bin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd-bin ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-sh ${PREFIX}/bin/drweb
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd-sh ${PREFIX}/sbin/drwebd
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-update ${PREFIX}/sbin

	${INSTALL_DATA_DIR} ${EGDIR}

	# --> Configuration files & evaluation keys
	${INSTALL_DATA} ${WRKDIR}/drweb32-ini ${EGDIR}/drweb32.ini
	${INSTALL_DATA} ${WRKSRC_BIN}/drweb.key ${EGDIR}/drweb.key
	${INSTALL_DATA} ${WRKSRC_BIN}/drwebd.key ${EGDIR}/drwebd.key

	# --> Minimal set of antivirus bases
	${INSTALL_DATA} ${WRKSRC_BIN}/lib/drweb32.dll ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/var/drweb/bases/drwebase.vdb ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/var/drweb/bases/drw43101.vdb ${EGDIR}

	# --> Documentation
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC_BIN}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC_BIN}/ChangeLog ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC_BIN}/doc/readme.daemon ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC_BIN}/doc/readme.scanner ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC_BIN}/doc/readme.eicar ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC_BIN}/update/readme.update ${DOCDIR}

post-install:
	# --> Remove old antivirus databases
	${RM} -f ${DRW_BASESDIR}/drw4[0-2]*.vdb
	${RM} -f ${DRW_BASESDIR}/drw430*.vdb
	${RM} -f ${DRW_BASESDIR}/drwtoday.vdb

.include "../../wip/drweb/Makefile.common"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
