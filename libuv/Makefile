# $NetBSD: Makefile,v 1.6 2015/05/08 18:17:30 jonthn Exp $
#

DISTNAME=	libuv-1.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libuv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://github.com/libuv/libuv
COMMENT=	Asynchronous event library, platform layer of node.js
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

USE_TOOLS+=     autoconf automake aclocal gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

HEADERS=	uv-bsd.h uv-darwin.h uv-linux.h uv-sunos.h uv-unix.h uv-win.h

pre-configure:
	${RUN} cd ${WRKSRC} && sh autogen.sh

post-install:
	for f in ${HEADERS}; do						\
		${INSTALL_DATA} ${WRKSRC}/include/$$f ${DESTDIR}${PREFIX}/include/$$f; \
	done

.include "../../mk/bsd.pkg.mk"
