# $NetBSD: Makefile,v 1.9 2011/04/26 09:24:52 moubctez Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake bash:run
GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-char-subscripts

MAKE_FILE=	GNUmakefile

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
