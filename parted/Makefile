# $NetBSD: Makefile,v 1.1.1.1 2005/08/12 04:38:24 jeremy-c-reed Exp $
#

DISTNAME=		parted-1.6.23
CATEGORIES=		sysutils
MASTER_SITES=		http://ftp.gnu.org/gnu/parted/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/parted/parted.html
COMMENT=		Create, destroy, resize, check, and copy partitions and file systems

GNU_CONFIGURE=		yes
INFO_FILES=		parted.info
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../wip/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
