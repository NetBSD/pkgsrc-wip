# $NetBSD$

GITHUB_PROJECT=	budgie-screensaver
GITHUB_TAG=	v4.0
DISTNAME=	v4.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=getsolus/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getsolus/budgie-screensaver/
COMMENT=	Requirement for budgie desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config intltool automake autoconf autoupdate

WRKSRC=			${WRKDIR}/budgie-screensaver-4.0
USE_PKGLOCALEDIR=	yes

pre-configure:
	cd ${WRKSRC} && autoupdate

do-configure:
	cd ${WRKSRC} && autoconf

#.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
