# $NetBSD: Makefile,v 1.2 2014/10/23 15:55:35 makoto Exp $

DISTNAME=	jgraphx-4.2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jgraph/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jgraph/jgraphx
COMMENT=	Java Swing diagramming (graph visualisation) library
LICENSE=	modified-bsd

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant



AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	lib/java

do-build:
	(cd ${WRKSRC}; env ${MAKE_ENV} ant )

do-install:
	(cd ${WRKSRC}; \
	${INSTALL_DATA} lib/jgraphx.jar ${DESTDIR}${PREFIX}/lib/java )

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
