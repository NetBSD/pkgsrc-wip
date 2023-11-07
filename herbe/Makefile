# $NetBSD$

# herbe does not contain a man page see below for info
# https://github.com/dudik/herbe/blob/1.0.0/README.md

DISTNAME=	herbe-1.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dudik/}

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://github.com/dudik/herbe/
COMMENT=	Daemon-less notifications without D-Bus
LICENSE=	mit

MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	PREFIX=${PREFIX}

DOC_DIR=	${DESTDIR}/${PREFIX}/share/doc/herbe
pre-install:
	mkdir -p ${DOC_DIR}
	cp ${WRKSRC}/README.md ${DOC_DIR}
	chmod 644 ${DOC_DIR}/README.md

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
