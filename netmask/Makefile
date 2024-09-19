# $NetBSD$

DISTNAME=	netmask-2.4.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlby/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tsao@disroot.org
HOMEPAGE=	https://github.com/tlby/netmask/
COMMENT=	Tool for generating terse netmasks in several common formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoreconf autoconf automake awk gmake digest makeinfo
GNU_CONFIGURE=	yes
INFO_FILES=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen

.include "../../mk/bsd.pkg.mk"
