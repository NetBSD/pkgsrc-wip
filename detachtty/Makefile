# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	detachtty_9
PKGNAME=	detachtty-9
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/detachtty/

MAINTAINER=	ddeus.sf@mailnull.com
HOMEPAGE=	ftp://ftp.linux.org.uk/pub/lisp/detachtty/
COMMENT=	Utility that lets you run interactive programs non-interactively
LICENSE=	gnu-gpl-v2
USE_TOOLS=	gmake

WRKSRC=			${WRKDIR}/detachtty-9
INSTALLATION_DIRS+=	bin/
INSTALLATION_DIRS+=	${PKGMANDIR}/man1/
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detachtty ${WRKSRC}/attachtty ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/detachtty.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
