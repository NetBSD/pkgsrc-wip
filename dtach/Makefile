# $NetBSD: Makefile,v 1.1 2006/06/16 20:39:28 fgudin Exp $
# FreeBSD Id: ports/misc/dtach/Makefile,v 1.2 2004/07/05 08:04:16 tobez Exp

DISTNAME=		dtach-0.7
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}

MAINTAINER=	fgudin@nerim.net
HOMEPAGE=	http://dtach.sourceforge.net/
COMMENT=	Small program that emulates the detach feature of screen

GNU_CONFIGURE=	yes
BUILD_TARGET=	dtach

PORTDOCS=	COPYING README dtach.spec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dtach ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/dtach.1 ${PREFIX:Q}/man/man1

	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/${PKGBASE:Q}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${PREFIX:Q}/share/doc/${PKGBASE:Q}
.endfor

.include "../../mk/bsd.pkg.mk"
