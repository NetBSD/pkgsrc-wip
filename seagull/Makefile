# $NetBSD: Makefile,v 1.1 2013/09/02 19:08:24 thomasklausner Exp $
#

DISTNAME=	seagull.svn
VERSION=	1.8.2
PKGNAME=	seagull-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gull/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gull.sourceforge.net/
COMMENT=	Open source multi-protocol traffic generator
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	seagull-1.8.2

WRKSRC=		${WRKDIR}/seagull.svn.LINUX
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison gmake ksh pax

# hardcodes -ldl
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}
# code isn't clean enough
BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS=	bin share/seagull/config

do-configure:
	cd ${WRKSRC} && ${TOOLS_PATH.ksh} build.ksh -target clean

do-build:
	cd ${WRKSRC} && ${TOOLS_PATH.ksh} build.ksh -target all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/exe-env && pax -pe -rw * ${DESTDIR}${PREFIX}/share/seagull
	${INSTALL_DATA} ${WRKSRC}/generator-control/remote-ctrl.xml ${DESTDIR}${PREFIX}/share/seagull/config

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
