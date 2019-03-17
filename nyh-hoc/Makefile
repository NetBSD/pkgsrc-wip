# $NetBSD$

DISTNAME=	hoc-9.2
PKGNAME=	nyh-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://nadav.harel.org.il/homepage/hoc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://nadav.harel.org.il/homepage/hoc/
COMMENT=	High Order Calculator
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hoc ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
