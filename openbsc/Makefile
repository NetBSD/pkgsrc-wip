# $NetBSD: Makefile,v 1.1 2011/08/02 23:05:26 khorben Exp $
#

DISTNAME=	openbsc-0.9.13
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	devel
MASTER_SITES=	http://openbsc.osmocom.org/trac/raw-attachment/wiki/Tarballs/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://openbsc.osmocom.org/
COMMENT=	openbsc

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

.include "../../wip/libosmocore/buildlink3.mk"
.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
