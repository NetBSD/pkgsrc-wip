# $NetBSD: Makefile,v 1.8 2012/09/29 17:05:53 asau Exp $
#

DISTNAME=		hasciicam-0.9
CATEGORIES=		graphics net
MASTER_SITES=		http://ascii.dyne.org/ \
			http://www.autistici.org/dyne/hasciicam/ \
			http://freesoftware.fsf.org/download/hasciicam/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ascii.dyne.org/
COMMENT=		Live ascii video on the web

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

ONLY_FOR_PLATFORM=	Linux-*-*

PKG_DESTDIR_SUPPORT=	none

.include "../../graphics/aalib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
