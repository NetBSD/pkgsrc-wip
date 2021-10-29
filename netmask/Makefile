# $NetBSD$

GITHUB_PROJECT=	netmask
GITHUB_TAG=	refs/tags/v2.4.4
DISTNAME=	v2.4.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	sysutils	
MASTER_SITES=	${MASTER_SITE_GITHUB:=tlby/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	tsao@disroot.org
HOMEPAGE=	https://github.com/tlby/netmask/
COMMENT=	Handy tool for generating terse netmasks in several common formats
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/netmask-2.4.4

USE_TOOLS+=     autoreconf autoconf automake awk gmake digest makeinfo
GNU_CONFIGURE=  yes
INFO_FILES=	yes
pre-configure:
	cd ${WRKSRC}; \
	./autogen
.include "../../mk/bsd.pkg.mk"
