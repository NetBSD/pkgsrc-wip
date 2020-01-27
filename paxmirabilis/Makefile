# $NetBSD: Makefile,v 1.3 2013/06/08 11:36:04 bsiegert Exp $
#

DISTNAME=	paxmirabilis-20171021
CATEGORIES=	archivers
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/mir/cpio/
EXTRACT_SUFX=	.cpio.gz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://launchpad.net/paxmirabilis
COMMENT=	Archiving utility for tar, cpio and ar
LICENSE=	miros

AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/pax
MAKE_ENV+=	OSTYPE=${OPSYS} MACHINE_OS=${OPSYS}
MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../mk/bsd.pkg.mk"
