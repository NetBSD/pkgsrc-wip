# $NetBSD: Makefile,v 1.4 2012/02/28 20:35:19 bartoszkuzma Exp $
#

DISTNAME=		sxid-4.2
CATEGORIES=		sysutils
MASTER_SITES=		http://linukz.org/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://linukz.org/sxid.shtml
COMMENT=		Suid, sgid file and directory checking
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

EGDIR=			share/examples/sxid
CONF_FILES=		${EGDIR}/sxid.conf ${PKG_SYSCONFDIR}/sxid.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/sxid ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/sxid.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/docs/sxid.conf.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA} ${WRKSRC}/docs/sxid.conf.example \
		${DESTDIR}${PREFIX}/${EGDIR}/sxid.conf

.include "../../mk/bsd.pkg.mk"
