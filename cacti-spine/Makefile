# $NetBSD: Makefile,v 1.15 2013/07/29 09:01:01 ahp-nils Exp $
#

DISTNAME=	cacti-spine-${VERSION}
#PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cacti.net/downloads/spine/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.cacti.net/spine_info.php
COMMENT=	Spine is a poller for Cacti for large installations
LICENSE=	gnu-lgpl-v2.1

VERSION=0.8.8a
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}

DEPENDS+=	cacti>=0.8.7:../../net/cacti

DOCDIR=			share/doc/cacti-spine
EXAMPLES_DIR=		examples
EGDIR=			${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
CONF_FILES=		${EGDIR}/spine.conf.dist ${PKG_SYSCONFDIR}/spine.conf
INSTALLATION_DIRS=	bin ${DOCDIR} ${DOCDIR}/${EXAMPLES_DIR} ${PKG_SYSCONFDIR}
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spine ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/spine.conf.dist ${DESTDIR}${PREFIX}/${DOCDIR}/${EXAMPLES_DIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE* ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
