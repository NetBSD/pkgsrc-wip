# $NetBSD$

DISTNAME=	1.21.22
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=guillemj/}
GITHUB_PROJECT=	dpkg
GITHUB_TAG=	refs/tags/1.21.22
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://github.com/guillemj/dpkg/
COMMENT=	Debian Package Manager
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/dpkg-1.21.22
USE_TOOLS+=		gmake msgfmt perl
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

DEPENDS+=		pkgconf>=0:../../devel/pkgconf
DEPENDS+=		autoconf>=2.60:../../devel/autoconf
DEPENDS+=		automake>=1.11:../../devel/automake
DEPENDS+=		libtool>=2.0:../../devel/libtool
DEPENDS+=		coreutils>=0:../../sysutils/coreutils
DEPENDS+=		gpatch>=0:../../wip/gpatch

PKGCONFIG_OVERRIDE+=	lib/dpkg/libdpkg.pc.in

pre-configure:
	cd ${WRKSRC} && echo ${DISTNAME} > .dist-version
	cd ${WRKSRC} && ./autogen


do-configure:
	cd ${WRKSRC} && \
			export LDFLAGS="-Wl,-R/usr/pkg/lib -L/usr/pkg/lib" && \
			export CFLAGS="-I/usr/pkg/include" && \
			export CXXFLAGS="-I/usr/pkg/include" && \
			export MSGMERGE="/usr/pkg/bin/msgmerge" && \
			export MSGFMT="/usr/pkg/bin/msgfmt" && \
			./configure --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && gmake

.include "../../mk/bsd.pkg.mk"
