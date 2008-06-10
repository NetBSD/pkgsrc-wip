# $NetBSD: Makefile,v 1.2 2008/06/10 13:29:38 moubctez Exp $

DISTNAME=	udns_0.0.9
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/udns/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.corpit.ru/mjt/udns.html
COMMENT=	Lightweight DNS resolver supporting asynchronous queries

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes

.include "options.mk"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/libudns.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/dnsget ${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/rblcheck ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/udns.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/udns.3 ${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/dnsget.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/rblcheck.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
