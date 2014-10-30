# $Id: Makefile,v 1.6 2014/10/30 08:54:37 bartoszkuzma Exp $
#

DISTNAME=		sxid-4.20130802
CATEGORIES=		sysutils
MASTER_SITES=		http://linukz.org/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://linukz.org/sxid.shtml
COMMENT=		Suid, sgid file and directory checking
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

EGDIR=			share/examples/sxid
CONF_FILES=		${EGDIR}/sxid.conf ${PKG_SYSCONFDIR}/sxid.conf

INSTALLATION_DIRS=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/sxid.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/sxid.conf

.include "../../mk/bsd.pkg.mk"
