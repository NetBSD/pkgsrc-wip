# $NetBSD: Makefile,v 1.4 2010/05/09 11:24:22 pdtafti Exp $

DISTNAME=	vpnc-script-20100223
CATEGORIES=	net security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://www.infradead.org/openconnect.html
COMMENT=	Improved config script for OpenConnect and vpnc

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
WRKSRC=		${WRKDIR}

PKG_SYSCONFSUBDIR?=	vpn
EGDIR=				${PREFIX}/share/examples/vpnc-script

INSTALLATION_DIRS=	${PKG_SYSCONFDIR} share/examples/vpnc-script
OWN_DIRS=			${PKG_SYSCONFDIR} share/examples/vpnc-script

CONF_FILES_PERMS+=	${EGDIR}/vpnc-script \
					${PKG_SYSCONFDIR}/vpnc-script \
					${ROOT_USER} ${ROOT_GROUP} 555

do-extract:
	${CP} ${FILESDIR}/vpnc-script ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
