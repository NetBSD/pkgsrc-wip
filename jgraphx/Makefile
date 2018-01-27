# $NetBSD: Makefile,v 1.2 2014/10/23 15:55:35 makoto Exp $

DISTNAME=	jgraphx-3_1_0_1
PKGNAME=	${DISTNAME:C/_/./g}
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.jgraph.com/downloads/jgraphx/archive/
LICENSE=	modified-bsd

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgraph/jgraphx
COMMENT=	Java Swing diagramming (graph visualisation) library
EXTRACT_SUFX=	.zip

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

WRKSRC=		${WRKDIR}/${PKGBASE}

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	lib/java/jgraphx

do-build:
	(cd ${WRKSRC}; ant )

do-install:
	(cd ${WRKSRC}; \
	${INSTALL_DATA} lib/jgraphx.jar ${DESTDIR}${PREFIX}/lib/java/jgraphx )

.include "../../mk/bsd.pkg.mk"
