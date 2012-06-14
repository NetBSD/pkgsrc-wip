# $NetBSD: Makefile,v 1.3 2012/06/14 16:15:33 othyro Exp $

DISTNAME=		csstidy-source-1.2
PKGNAME=		csstidy-1.2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=csstidy/}
EXTRACT_SUFX=		.zip

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://csstidy.sourceforge.net/
COMMENT=		Opensource CSS parser
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
USE_TOOLS+=		sh gmake
USE_LANGUAGES=		c++

do-build:
	cd ${WRKSRC} && ${SH} ./compile.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csstidy ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
