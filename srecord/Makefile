# $NetBSD: Makefile,v 1.4 2013/01/19 13:17:41 othyro Exp $
#

DISTNAME=	srecord-1.61
CATEGORIES=	devel
MASTER_SITES=	http://srecord.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://srecord.sourceforge.net/
COMMENT=	Manipulate EPROM load files
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
