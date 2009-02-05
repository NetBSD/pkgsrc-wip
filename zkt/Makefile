# $NetBSD: Makefile,v 1.1.1.1 2009/02/05 14:52:12 pettai Exp $
#

DISTNAME=	zkt-0.98
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zkt/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://zkt.sourceforge.net/
COMMENT=	Tool to manage keys and signatures for DNSSEC-zones

WRKSRC=		${WRKDIR}/${DISTNAME}

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-zkt ${DESTDIR}${PREFIX}/sbin/dnssec-zkt
	${INSTALL_PROGRAM} ${WRKSRC}/dnssec-signer ${DESTDIR}${PREFIX}/sbin/dnssec-signer
	${INSTALL_PROGRAM} ${WRKSRC}/zkt-soaserial ${DESTDIR}${PREFIX}/sbin/zkt-soaserial
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-zkt.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dnssec-zkt.8
	${INSTALL_MAN} ${WRKSRC}/man/dnssec-signer.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dnssec-signer.8

.include "../../mk/bsd.pkg.mk"
