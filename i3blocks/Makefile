# $NetBSD$

DISTNAME=	i3blocks-1.5
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=vivien/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vivien/i3blocks/
COMMENT=	Hacker-friendly status_command for Sway and i3
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

# pkg-config needed for autoreconf step
USE_TOOLS+=	autoconf automake autoreconf pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
