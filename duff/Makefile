# $NetBSD: Makefile,v 1.2 2012/02/10 08:40:25 bartoszkuzma Exp $
#

DISTNAME=	duff-0.5.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=duff/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://duff.sourceforge.net/
COMMENT=	Quickly finds duplicates in a given set of files
# LICENSE=	zlib-license http://www.opensource.org/licenses/zlib-license.php

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
