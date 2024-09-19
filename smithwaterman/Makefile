# $NetBSD$

DISTNAME=	smithwaterman-0.0.0.20160702
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=ekg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ekg/smithwaterman
COMMENT=	Smith-waterman-gotoh alignment algorithm
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
INSTALL_TARGET=	install-strip
GITHUB_TAG=	2610e259611ae4cde8f03c72499d28f03f6d38a7

pre-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -s libsw.so.1 libsw.so

.include "../../mk/bsd.pkg.mk"
