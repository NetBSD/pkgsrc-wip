# $NetBSD: Makefile,v 1.1.1.1 2003/04/25 19:52:40 virtus Exp $
#

DISTNAME=		jigdo-0.6.9
CATEGORIES=		misc
MASTER_SITES=		http://home.in.tum.de/~atterer/jigdo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://home.in.tum.de/~atterer/jigdo/
COMMENT=		download manager and ISO image constructor

DEPENDS+=		wget>=1.8.2:../../net/wget

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes

CONFIGURE_ARGS+=	--without-gui

.include "../../www/libwww/buildlink2.mk"
.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
