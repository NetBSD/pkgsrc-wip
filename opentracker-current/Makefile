# $NetBSD: Makefile,v 1.3 2009/02/24 16:20:14 thomasklausner Exp $

DISTNAME=		opentracker-0.0.${OPENTRACKER_PKG_VERSION}
CATEGORIES=		net

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://erdgeist.org/arts/software/opentracker/
COMMENT=		High performance bittorrent tracker

WRKSRC=			${WRKDIR}/opentracker

CFLAGS+=		-I${BUILDLINK_PREFIX.libowfat}/include/libowfat

CVS_REPOSITORIES=	opentracker
CVS_ROOT.opentracker=	:pserver:anoncvs:@cvs.erdgeist.org:/home/cvsroot
CVS_MODULE.opentracker=	opentracker

INSTALLATION_DIRS=	bin share/doc/opentracker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opentracker ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/opentracker

.include "../../mk/bsd.prefs.mk"

OPENTRACKER_PKG_VERSION!=	${DATE} +%Y%m%d

.include "../../devel/libowfat/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
