# $NetBSD: Makefile,v 1.5 2004/04/07 10:01:03 bubuchka Exp $

DRW_CLIENT_NAME=	clients-shared

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Shared files of clients to DrWeb Daemon antivirus

NO_CONFIGURE=		yes
NO_BUILD=		yes

DRW_TEMPL_DIR=		${WRKSRC}/etc/templates/en

# ATTENTION: the MIO (etc/mio) have it's own notification templates
CONF_FILES=								\
	${EGDIR}/admin-archive.msg ${PKG_SYSCONFDIR}/admin-archive.msg	\
	${EGDIR}/admin-error.msg ${PKG_SYSCONFDIR}/admin-error.msg	\
	${EGDIR}/admin-rule.msg ${PKG_SYSCONFDIR}/admin-rule.msg	\
	${EGDIR}/admin-virus.msg ${PKG_SYSCONFDIR}/admin-virus.msg	\
	${EGDIR}/rcpts-virus.msg ${PKG_SYSCONFDIR}/rcpts-virus.msg	\
	${EGDIR}/sender-archive.msg ${PKG_SYSCONFDIR}/sender-archive.msg\
	${EGDIR}/sender-error.msg ${PKG_SYSCONFDIR}/sender-error.msg	\
	${EGDIR}/sender-skip.msg ${PKG_SYSCONFDIR}/sender-skip.msg	\
	${EGDIR}/sender-virus.msg ${PKG_SYSCONFDIR}/sender-virus.msg	\
	${EGDIR}/addresses.conf	${PKG_SYSCONFDIR}/addresses.conf	\
	${EGDIR}/users.conf ${PKG_SYSCONFDIR}/users.conf		\
	${EGDIR}/viruses.conf ${PKG_SYSCONFDIR}/viruses.conf

do-install:
	# --> Common documentation
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Acknowledgements ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.RUS ${DOCDIR}

	# --> Common configuration files
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/admin_archive.msg		\
		${EGDIR}/admin-archive.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/admin_error.msg		\
		${EGDIR}/admin-error.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/admin_rule.msg			\
		${EGDIR}/admin-rule.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/admin_virus.msg		\
		${EGDIR}/admin-virus.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/rcpts_virus.msg		\
		${EGDIR}/rcpts-virus.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/sender_archive.msg		\
		${EGDIR}/sender-archive.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/sender_error.msg		\
		${EGDIR}/sender-error.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/sender_skip.msg		\
		${EGDIR}/sender-skip.msg
	${INSTALL_DATA} ${DRW_TEMPL_DIR}/sender_virus.msg		\
		${EGDIR}/sender-virus.msg
	${INSTALL_DATA} ${WRKSRC}/etc/addresses.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/users.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/viruses.conf ${EGDIR}

.include "../../wip/drweb-clients-shared/Makefile.common"
.include "../../mk/bsd.pkg.mk"
