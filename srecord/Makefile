# $NetBSD: Makefile,v 1.3 2012/10/07 16:23:16 asau Exp $
#

DISTNAME=	srecord-1.50
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://srecord.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://srecord.sourceforge.net/
COMMENT=	Manipulate EPROM load files

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
