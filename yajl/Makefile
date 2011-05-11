# $NetBSD: Makefile,v 1.2 2011/05/11 16:27:12 pallegra Exp $
#

DISTNAME=	yajl-1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://github.com/downloads/lloyd/yajl/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://lloyd.github.com/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes

USE_LANGUAGES=	c

MAKE_ENV+=	MKDIR="${MKDIR}"
MAKE_ENV+=	CP="${CP}"

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/src/

BUILD_DIRS=	src

.include "../../mk/bsd.pkg.mk"
