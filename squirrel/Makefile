# $NetBSD$

PKGNAME=	squirrel-3.2
DISTNAME=	squirrel_${PKGVERSION_NOREV:S/./_/g}_stable
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squirrel-lang.org/
COMMENT=	The Squirrel programming language
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/squirrel3
NO_CONFIGURE=	yes
BUILD_TARGET=	sq32

# XXX something like this would be nice
#.if !empty(${MACHINE_ARCH:M*64*})
#BUILD_TARGET=	sq64
#.else
#BUILD_TARGET=	sq32
#.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sq ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
