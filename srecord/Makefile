# $NetBSD: Makefile,v 1.1.1.1 2009/07/14 09:10:12 yhardy Exp $
#

DISTNAME=	srecord-1.50
CATEGORIES=	devel
MASTER_SITES=	http://srecord.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://srecord.sourceforge.net/
COMMENT=	Manipulate EPROM load files

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
