# $NetBSD$

DISTNAME=	buddy-2.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=utwente-fmt/}
GITHUB_PROJECT=	buddy
GITHUB_RELEASE=	v2.4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/utwente-fmt/buddy/
COMMENT=	Github based (newer) version of devel/buddy
#LICENSE=	# unfortunately not specified, not in devel/buddy either

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libbdd.pc.in

.include "../../mk/bsd.pkg.mk"
