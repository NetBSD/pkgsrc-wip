# $NetBSD: Makefile,v 1.2 2003/09/11 15:20:28 bubuchka Exp $

.if defined(OPSYS) && ${OPSYS} == "Linux"
DISTNAME=	drweb-4.29.5-glibc.2.3
.else
DISTNAME=	drweb-4.29.5-freebsd4
.endif
PKGNAME=	drweb-4.29.5
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/4.29.5/			\
		ftp://ftp.drweb.ru/pub/unix/				\
		http://drweb.spb.ru/download/unix/

MAINTAINER=	mishka@terabyte.com.ua
HOMEPAGE=	http://www.drweb.ru/
COMMENT=	DrWeb Antivirus Suite

ONLY_FOR_PLATFORM= FreeBSD-4.[0-9]*-i386 Linux-*-i[3-6]86		\
		NetBSD-1.[6-9]*-i386 NetBSD-2.[0-9]-i386

# The following needed for drweb-update script only
DEPENDS+=	wget>=1.7:../../net/wget
USE_PERL5=	YES

NO_BUILD=	YES

PKG_GROUPS=	${DRW_GROUP}
PKG_USERS=	${DRW_USER}:${PKG_GROUPS}::DrWeb\\ AntiVirus

OWN_DIRS_PERMS+= ${DRW_DIR} ${DRW_USER} ${DRW_GROUP} 0755
OWN_DIRS_PERMS+= ${DRW_BASESDIR} ${DRW_USER} ${DRW_GROUP} 0755
OWN_DIRS_PERMS+= ${DRW_INFECTDIR} ${DRW_USER} ${DRW_GROUP} 0700

CONF_FILES=	${EGDIR}/drweb32.ini ${PKG_SYSCONFDIR}/drweb32.ini
SUPPORT_FILES=	${EGDIR}/drweb.key ${PKG_SYSCONFDIR}/drweb.key
SUPPORT_FILES+=	${EGDIR}/drwebd.key ${PKG_SYSCONFDIR}/drwebd.key
SUPPORT_FILES+=	${EGDIR}/drweb32.dll ${DRW_BASESDIR}/drweb32.dll
SUPPORT_FILES+=	${EGDIR}/drwebase.vdb ${DRW_BASESDIR}/drwebase.vdb

RCD_SCRIPTS=		drwebd
RCD_SCRIPT_SRC.drwebd=	${FILESDIR}/drwebd-rcd.src

# Note: We'll not use drweb's own configuration / building / installation
# facilities so as its all are very ugly.

do-configure:
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drweb-sh.src > ${WRKDIR}/drweb-sh
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drwebd-sh.src > ${WRKDIR}/drwebd-sh
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drweb32-ini.src > ${WRKDIR}/drweb32-ini
	@${SED} ${FILES_SUBST_SED}					\
		${WRKSRC}/install/opt/drweb/update/update.pl >		\
		${WRKDIR}/drweb-update
.if defined(OPSYS) && ${OPSYS} == "NetBSD"
	${MV} ${WRKSRC}/install/opt/drweb/drweb.static ${WRKDIR}/drweb-bin
	${MV} ${WRKSRC}/install/opt/drweb/drwebd.static	${WRKDIR}/drwebd-bin
.else
	${MV} ${WRKSRC}/install/opt/drweb/drweb ${WRKDIR}/drweb-bin
	${MV} ${WRKSRC}/install/opt/drweb/drwebd ${WRKDIR}/drwebd-bin
.endif

do-install:
	# --> Executables
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-bin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd-bin ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-sh ${PREFIX}/bin/drweb
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd-sh ${PREFIX}/sbin/drwebd
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-update ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${EGDIR}

	# --> Configuration files
	${INSTALL_DATA} ${WRKDIR}/drweb32-ini				\
		${EGDIR}/drweb32.ini
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/drweb.key		\
		${EGDIR}/drweb.key
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/drwebd.key		\
		${EGDIR}/drwebd.key

	# --> Minimal set of antivirus bases
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/lib/drweb32.dll ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/install/var/drweb/bases/drwebase.vdb ${EGDIR}

	# --> Documentation
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/ChangeLog ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/doc/readme.scanner ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/doc/readme.daemon ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/doc/readme.eicar ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/clients/drwebd-api ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/install/opt/drweb/update/readme.update \
		${DOCDIR}

.include "../../wip/oshavercd.mk"
.include "../../wip/drweb/Makefile.common"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
