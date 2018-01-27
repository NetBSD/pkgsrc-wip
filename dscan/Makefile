# $NetBSD: Makefile,v 1.3 2015/06/10 13:43:16 ahp-nils Exp $

VERSION=		8ebbeb20c5721567eeba80e5cec65155a488291f
DISTNAME=		${VERSION}
PKGNAME=		dscan-0.1
CATEGORIES=		net
MASTER_SITES=		https://github.com/dugsong/dscan/archive/

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://github.com/dugsong/dscan
COMMENT=		Network scanner
LICENSE=		original-bsd

DEPENDS+=		wget-[0-9]*:../../net/wget
WRKSRC=			${WRKDIR}/dscan-${VERSION}
GNU_CONFIGURE=		yes
INSTALLATION_DIRS+=	sbin ${PKGMANDIR}/man8 ${DOCDIR}
AUTO_MKDIRS=		yes
DOCDIR=			share/doc/dscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dscan ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dscan.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../net/libdnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
