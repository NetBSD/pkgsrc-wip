# $NetBSD: Makefile,v 1.1 2011/04/02 16:03:59 locutus42 Exp $
#

DISTNAME=		mscgen-src-${VERSION}
PKGNAME=		mscgen-${VERSION}
VERSION=		0.18
CATEGORIES=		devel graphics
MASTER_SITES=		http://www.mcternan.me.uk/mscgen/software/

MAINTAINER=		jan.m.danielsson@gmail.com
HOMEPAGE=		http://www.mcternan.me.uk/mscgen/
COMMENT=		Tool for drawing call sequence graphs
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config

WRKSRC=			${WRKDIR}/mscgen-${VERSION}

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
