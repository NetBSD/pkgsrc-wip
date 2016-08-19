# $NetBSD$

DISTNAME=	ympd-1.3.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=notandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ympd.org/
COMMENT=	Standalone MPD Web GUI written in C
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes

USE_LANGUAGES=	c c++

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
