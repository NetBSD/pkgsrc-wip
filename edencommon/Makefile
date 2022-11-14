# $NetBSD$

DISTNAME=	edencommon-2022.11.07.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebookexperimental/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebookexperimental/edencommon/
COMMENT=	Shared library for Watchman and Eden projects
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/google-glog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
