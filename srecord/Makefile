# $NetBSD$
#

DISTNAME=	v${PKGVER}
PKGNAME=	srecord-${PKGVER}
PKGVER=		1.65
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sierrafoxtrot/srecord/archive/refs/tags/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://srecord.sourceforge.net/
COMMENT=	Manipulate EPROM load files
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	groff

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/srecord-${PKGVER}

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
