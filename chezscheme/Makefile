# $NetBSD$

GITHUB_PROJECT=	ChezScheme
VERSION=	9.4
PKGNAME=	${GITHUB_PROJECT:tl}-${VERSION}
DISTNAME=	v${VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=cisco/}
GITHUB_TAG=     ${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTFILES=	ChezScheme-9.4.tar.gz \
		zlib-1.2.8.tar.gz \
		nanopass-framework-scheme-1.9.tar.gz \
		stex-1.2.1.tar.gz
SITES.zlib-1.2.8.tar.gz= -https://github.com/madler/zlib/archive/v1.2.8.tar.gz
SITES.ChezScheme-9.4.tar.gz= -https://github.com/cisco/ChezScheme/archive/v9.4.tar.gz
SITES.nanopass-framework-scheme-1.9.tar.gz= -https://github.com/nanopass/nanopass-framework-scheme/archive/v1.9.tar.gz
SITES.stex-1.2.1.tar.gz= -https://github.com/dybvig/stex/archive/v1.2.1.tar.gz

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://cisco.github.io/ChezScheme/
COMMENT=	Cisco implementation of the Scheme programming language
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/ChezScheme-9.4
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c

pre-configure:
	cd ${WRKSRC} && rmdir stex && mv ../stex-1.2.1 stex && \
		        rmdir zlib && mv ../zlib-1.2.8 zlib &&  \
			rmdir nanopass && mv ../nanopass-framework-scheme-1.9 nanopass
do-configure:
	cd ${WRKSRC} && ./configure --installprefix=${PREFIX} \
                                    --installman=${PREFIX}/${PKGMANDIR} \
                                    --temproot=${DESTDIR} \
                                    LDFLAGS="${LDFLAGS}"

BUILD_TARGET=build

.include "../../mk/curses.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
