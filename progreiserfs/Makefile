# $NetBSD: Makefile,v 1.2 2004/08/17 18:31:42 tvierling Exp $
#

DISTNAME=	progsreiserfs-0.3.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://reiserfs.osdn.org.ua/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://reiserfs.osdn.org.ua/
COMMENT=	Library to manipulate reiserfs filesystems

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
LIBTOOL_LA_FILES+=	lib/libdal.la
LIBTOOL_LA_FILES+=	lib/libreiserfs.la
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
