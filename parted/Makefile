# $NetBSD: Makefile,v 1.6 2013/05/01 20:17:42 kristerw Exp $
#

DISTNAME=		parted-1.6.23
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=parted/}
LICENSE=		gnu-gpl-v3

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		https://www.gnu.org/software/parted/parted.html
COMMENT=		Create, destroy, resize, check, and copy partitions and file systems

ONLY_FOR_PLATFORM=	Linux-*-*


GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
