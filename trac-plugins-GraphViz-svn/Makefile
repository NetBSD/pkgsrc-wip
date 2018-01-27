# $NetBSD: Makefile,v 1.9 2015/08/04 20:04:15 thomasklausner Exp $

SVNVERSION=		13275
UPSTREAM_VERSION=	0.7.7
VERSION=		${UPSTREAM_VERSION}.${SVNVERSION}
DISTNAME=		TracGraphViz-${VERSION}
PKGNAME=		trac-plugins-GraphViz-${VERSION}
# Empty to avoid default setting.
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		# not defined

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	https://trac-hacks.org/wiki/GraphVizPlugin
COMMENT=	Graphviz plugin for Trac

DEPENDS+=	trac>=0.11:../../www/trac

EGG_NAME=	graphviz-${UPSTREAM_VERSION}dev_r0

SVN_REPOSITORIES=	graphviz
SVN_REPO.graphviz=	https://trac-hacks.org/svn/graphvizplugin/trunk
SVN_REVISION.graphviz=	${SVNVERSION}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 13275/0.7.7

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/graphviz

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
