# $NetBSD$
#

DISTNAME=	quickjs-2019-07-09
CATEGORIES=	lang
MASTER_SITES=	https://bellard.org/quickjs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bellard.org/quickjs/
COMMENT=	Small and embeddable Javascript engine

LICENSE=	mit
USE_TOOLS=	gmake

INSTALLATION_DIRS+=	bin lib include/quickjs

post-extract:
	cd ${WRKSRC}; \
	${SED} -e 's:^prefix=.*:prefix='${PREFIX}':' <Makefile >Makefile.new; \
	mv Makefile.new Makefile

.include "../../mk/bsd.pkg.mk"
