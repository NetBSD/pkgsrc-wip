# $NetBSD: Makefile,v 1.1.1.1 2003/04/10 18:51:53 jmmv Exp $

DISTNAME=	drweb-4.29.5-freebsd4
PKGNAME=	drweb-4.29.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/4.29.5/			\
		http://drweb.spb.ru/download/unix/

MAINTAINER=	mishka@terabyte.com.ua
HOMEPAGE=	http://www.drweb.ru/
COMMENT=	DrWeb antivirus suite, FreeBSD version

# The following needed for drweb-update script only
DEPENDS=	wget>=1.7:../../net/wget

ONLY_FOR_PLATFORM= NetBSD-*-i386

NO_BUILD=	YES

PKG_GROUPS=	${DRW_GROUP}
PKG_USERS=	${DRW_USER}:${PKG_GROUPS}::DrWeb\\ Daemon

RCD_SCRIPTS=	drwebd

OWN_DIRS_PERMS+= ${DRW_DIR} ${DRW_USER} ${DRW_GROUP} 0755
OWN_DIRS_PERMS+= ${DRW_BASESDIR} ${DRW_USER} ${DRW_GROUP} 0755
OWN_DIRS_PERMS+= ${DRW_INFECTDIR} ${DRW_USER} ${DRW_GROUP} 0700

CONF_FILES=	${EGDIR}/drweb32.ini ${PKG_SYSCONFDIR}/drweb32.ini
SUPPORT_FILES=	${EGDIR}/drweb.key ${PKG_SYSCONFDIR}/drweb.key
SUPPORT_FILES+=	${EGDIR}/drwebd.key ${PKG_SYSCONFDIR}/drwebd.key
SUPPORT_FILES+=	${EGDIR}/drweb32.dll ${DRW_BASESDIR}/drweb32.dll
SUPPORT_FILES+=	${EGDIR}/drwebase.vdb ${DRW_BASESDIR}/drwebase.vdb

# Note: We'll not use drweb's own configuration / building / installation
# facilities so as its all are very ugly.

do-configure:
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drweb32.ini > ${WRKDIR}/drweb32.ini
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drweb-nb.sh > ${WRKDIR}/drweb
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drwebd-nb.sh > ${WRKDIR}/drwebd
	@${SED} ${FILES_SUBST_SED}					\
		${WRKSRC}/install/opt/drweb/update/update.pl >		\
		${WRKDIR}/drweb-update
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/drwebd-rcd.sh > ${WRKDIR}/drwebd.sh

post-configure:
	${MV} ${WRKSRC}/install/opt/drweb/drweb.static ${WRKDIR}/drweb-fbsd
	${MV} ${WRKSRC}/install/opt/drweb/drwebd.static ${WRKDIR}/drwebd-fbsd

do-install:
	# --> Executables
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-fbsd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd-fbsd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/drweb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/drweb-update ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/drwebd.sh ${PREFIX}/etc/rc.d/drwebd

	${INSTALL_DATA_DIR} ${EGDIR}

	# --> Configuration files
	${INSTALL_DATA} ${WRKDIR}/drweb32.ini				\
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

.include "Makefile.common"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
