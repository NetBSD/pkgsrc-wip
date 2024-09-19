# $NetBSD: Makefile,v 1.10 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	rdup-1.1.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.miek.nl/projects/rdup/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://www.miek.nl/projects/rdup/
COMMENT=	Backup utility listing changed files only
LICENSE=	gnu-gpl-v3

REPLACE_BASH+=	sh/rdup-simple.in

USE_TOOLS+=	pkg-config gmake bash:run
GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-char-subscripts

MAKE_FILE=	GNUmakefile

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
