# $NetBSD: Makefile,v 1.6 2010/11/02 10:01:24 emil_s Exp $
#

DISTNAME=	rdup-1.1.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.miek.nl/projects/rdup/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://www.miek.nl/projects/rdup/
COMMENT=	Backup utility listing changed files only
LICENSE=	gnu-gpl-v3

REPLACE_BASH+=	sh/rdup-simple.in


PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config gmake bash:run

CFLAGS+=	-Wno-char-subscripts

MAKE_FILE=	GNUmakefile


.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../wip/libnettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
