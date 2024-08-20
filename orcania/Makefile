# $NetBSD$

DISTNAME=	orcania-2.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=babelouest/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/babelouest/orcania/
COMMENT=	Potluck with different functions for different purposes for C programs
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	liborcania.pc.in

.include "../../mk/bsd.pkg.mk"
