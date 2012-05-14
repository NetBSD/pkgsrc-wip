# $NetBSD: Makefile,v 1.6 2012/05/14 14:59:11 hfath Exp $

DISTNAME=	vpnc-script-20120514
CATEGORIES=	net security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pouya@san-serriffe.org
HOMEPAGE=	http://www.infradead.org/openconnect.html
COMMENT=	Improved config script for OpenConnect and vpnc

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	YES
WRKSRC=		${WRKDIR}

EGDIR=			${PREFIX}/share/examples/vpnc-script
INSTALLATION_DIRS=	${EGDIR}
CONF_FILES_PERMS=	${EGDIR}/vpnc-script \
				${PKG_SYSCONFDIR}/vpnc-script \
				${ROOT_USER} ${ROOT_GROUP} 555

do-extract:
	${CP} ${FILESDIR}/vpnc-script ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
