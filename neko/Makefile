# $NetBSD$

DISTNAME=	neko-2.3.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=HaxeFoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./-/g}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The Neko virtual machine
LICENSE=	mit

EXTRACT_USING=	gtar
USE_LANGUAGES=	c
USE_CMAKE=	yes

.include "options.mk"

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
