# $NetBSD: Makefile,v 1.9 2015/02/17 19:55:37 keckhardt Exp $

DISTNAME=	vpnc-script-20130311
CATEGORIES=	net security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect/vpnc-script.html
COMMENT=	Improved config script for OpenConnect and vpnc
LICENSE=	gnu-gpl-v2

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
