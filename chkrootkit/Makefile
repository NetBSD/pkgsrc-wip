# $NetBSD: Makefile,v 1.6 2004/02/17 14:45:24 minskim Exp $
#

DISTNAME=		chkrootkit
PKGNAME=		chkrootkit-${VERSION}
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.chkrootkit.org/
COMMENT=		Locally checks for signs of a rootkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/chkrootkit-${VERSION}
VERSION=		0.43
DIST_SUBDIR=		${PKGNAME}
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes

INSTALLATION_DIRS+=	bin

do-install:
	for A in chkdirs chklastlog chkproc chkwtmp ifpromisc strings-static ;\
	do ${INSTALL_PROGRAM} ${WRKSRC}/$$A ${PREFIX}/bin ; done

.include "../../mk/bsd.pkg.mk"
