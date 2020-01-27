# $NetBSD: Makefile,v 1.4 2012/10/03 21:06:07 asau Exp $

DISTNAME=		opentracker-0.0
CATEGORIES=		net
CVS_ROOT=		:pserver:anoncvs:@cvs.erdgeist.org:/home/cvsroot

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://erdgeist.org/arts/software/opentracker/
COMMENT=		High performance bittorrent tracker

WRKSRC=			${WRKDIR}/opentracker

CFLAGS+=		-I${BUILDLINK_PREFIX.libowfat}/include/libowfat


INSTALLATION_DIRS=	bin share/doc/opentracker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opentracker ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/opentracker

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libowfat/buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
