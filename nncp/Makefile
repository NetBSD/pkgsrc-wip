# $NetBSD$

DISTNAME=	nncp-8.7.2
CATEGORIES=	net
MASTER_SITES=	https://www.nncpgo.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dvollen@gmail.com
HOMEPAGE=	https://www.nncpgo.org/
COMMENT=	Utilities for store-and-forward networking (modernized UUCP)
LICENSE=	gnu-gpl-v3

INFO_FILES=	yes

NNCP_SPOOLDIR?=		${VARBASE}/spool/nncp

PKG_SYSCONFSUBDIR?=	${PKGBASE}

RCD_SCRIPTS=	nncp-caller nncp-daemon nncp-toss

post-extract:
	${CP} ${FILESDIR}/nncp-caller-daemonize.sh ${WRKSRC}
	${CP} ${FILESDIR}/nncp-daemon-daemonize.sh ${WRKSRC}
	${CP} ${FILESDIR}/nncp-toss-daemonize.sh ${WRKSRC}

SUBST_CLASSES+=			daemonize
SUBST_STAGE.daemonize=		pre-configure
SUBST_MESSAGE.daemonize=	Customizing daemonizing scripts
SUBST_FILES.daemonize=		nncp-caller-daemonize.sh nncp-daemon-daemonize.sh nncp-toss-daemonize.sh
SUBST_VARS.daemonize=		PREFIX VARBASE

post-install:
	${INSTALL_SCRIPT} -d  ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/nncp-caller-daemonize.sh ${DESTDIR}${PREFIX}/libexec/nncp-caller
	${INSTALL_SCRIPT} ${WRKSRC}/nncp-daemon-daemonize.sh ${DESTDIR}${PREFIX}/libexec/nncp-daemon
	${INSTALL_SCRIPT} ${WRKSRC}/nncp-toss-daemonize.sh ${DESTDIR}${PREFIX}/libexec/nncp-toss

# CONF_FILES+=	${PKG_SYSCONFDIR}/nnc
    
.include "../../lang/go/version.mk"
.include "../../mk/bsd.pkg.mk"
