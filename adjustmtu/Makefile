# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:30 asau Exp $
#

DISTNAME=	adjustmtu-1.00
PKGNAME=	${DISTNAME:S/00/0/}
CATEGORIES=	net
MASTER_SITES=	http://www.nerv.org/~ryo/files/programs/adjustmtu/
LICENSE=	2-clause-bsd

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Detect MTU size and set MTU size of routing table

#ONLY_FOR_PLATFORM=	FreeBSD-* NetBSD-* OpenBSD-*

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1.00//}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adjustmtu ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
