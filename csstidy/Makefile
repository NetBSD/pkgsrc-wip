# $NetBSD: Makefile,v 1.5 2013/03/21 17:34:50 shattered Exp $

DISTNAME=		csstidy-source-1.2
PKGNAME=		csstidy-1.2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csstidy/}
EXTRACT_SUFX=		.zip

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		https://csstidy.sourceforge.net/
COMMENT=		Opensource CSS parser
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
USE_TOOLS+=		sh gmake
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SH} ./compile.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csstidy ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
