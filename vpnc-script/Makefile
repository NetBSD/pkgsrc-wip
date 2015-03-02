# $NetBSD: Makefile,v 1.11 2015/03/02 14:56:11 keckhardt Exp $

DISTNAME=	vpnc-script-20140805
CATEGORIES=	net security
MASTER_SITES=	http://git.infradead.org/users/dwmw2/vpnc-scripts.git/blob_plain/HEAD:/
DISTFILES=	vpnc-script

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.infradead.org/openconnect/vpnc-script.html
# see also http://git.infradead.org/users/dwmw2/vpnc-scripts.git
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
