# $NetBSD: Makefile,v 1.1.1.1 2010/08/08 19:09:31 jihbed Exp $
#

DISTNAME=	mmdb_1.21.orig
PKGNAME=	${DISTNAME:S/_/-/S/.orig//}
CATEGORIES=	biology databases
MASTER_SITES=	http://mirrors.cytanet.com.cy/linux/ubuntu/archive/pool/universe/m/mmdb/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://strucbio.biologie.uni-konstanz.de/ccp4wiki/index.php/Mmdb
COMMENT=	Macromolecular coordinate library
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/mmdb-1.21
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
