# $NetBSD: Makefile,v 1.5 2004/03/12 16:45:10 minskim Exp $

DRW_CLIENT_NAME=	smf

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Sendmail MTA filter for DrWeb Daemon antivirus

RCD_SCRIPTS=		drweb-smf

PKG_GROUPS=		${DRW_GROUP}
PKG_USERS=		${DRW_USER}:${PKG_GROUPS}::DrWeb\\ AntiVirus

OWN_DIRS_PERMS+=	${DRW_DIR} ${DRW_USER} ${DRW_GROUP} 0755
OWN_DIRS_PERMS+=	${DRW_INFECTDIR} ${DRW_USER} ${DRW_GROUP} 0700

DRW_SMF_SOCKFILE=	${DRW_RUNDIR}/drweb-smf.sock
FILES_SUBST+=		DRW_SMF_SOCKFILE=${DRW_SMF_SOCKFILE}

CONF_FILES=		${EGDIR}/drweb-smf.conf ${PKG_SYSCONFDIR}/drweb-smf.conf

do-configure:
	@${SED} ${FILES_SUBST_SED}					\
		${WRKSRC}/etc/drweb_smf.conf > ${WRKDIR}/drweb-smf.conf
	@${SED} ${FILES_SUBST_SED}					\
		${FILESDIR}/sendmail.mc.addon > ${WRKDIR}/sendmail.mc.addon

do-install:
	# --> Executables
	${INSTALL_PROGRAM} ${WRKSRC}/drweb-smf ${PREFIX}/sbin

	# --> Configuration files
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/drweb-smf.conf ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/sendmail.mc.addon ${EGDIR}

	# --> Documentation
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sendmail/addresses_list.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sendmail/conf_file.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sendmail/notify.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sendmail/readme ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sendmail/users_list.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sendmail/viruses_list.txt ${DOCDIR}

.include "../../wip/drweb-clients-shared/Makefile.common"
.include "../../mail/libmilter/buildlink2.mk"
.include "../../wip/mk/rcd.mk"
.include "../../mk/bsd.pkg.mk"
