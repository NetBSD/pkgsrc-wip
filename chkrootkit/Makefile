# $NetBSD: Makefile,v 1.3 2004/02/17 14:37:18 minskim Exp $
#

DISTNAME=		chkrootkit
PKGNAME=		chkrootkit-${VERSION}
WRKSRC=			${WRKDIR}/chkrootkit-${VERSION}
CATEGORIES=		wip
MASTER_SITES=		ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.chkrootkit.org/
COMMENT=		Locally checks for signs of a rootkit

VERSION=		0.43
DIST_SUBDIR=		${PKGNAME}
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes

do-install:
	for A in chkdirs chklastlog chkproc chkwtmp ifpromisc strings-static ;\
	do ${INSTALL_PROGRAM} ${WRKSRC}/$$A ${PREFIX}/bin ; done

.include "../../mk/bsd.pkg.mk"
