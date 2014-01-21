# $NetBSD: Makefile,v 1.7 2014/01/21 22:13:15 lexort Exp $

SVNVERSION=		13275
UPSTREAM_VERSION=	0.7.7
VERSION=	${UPSTREAM_VERSION}.${SVNVERSION}
DISTNAME=	TracGraphViz-${VERSION}
PKGNAME=	trac-plugins-GraphViz-${VERSION}
# Empty to avoid default setting.
PKGREVISION=	1
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://trac-hacks.org/wiki/GraphVizPlugin
COMMENT=	Graphviz plugin for Trac

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

EGG_NAME=	graphviz-${UPSTREAM_VERSION}dev

SVN_REPOSITORIES=	graphviz
SVN_ROOT.graphviz=	http://trac-hacks.org/svn/graphvizplugin/trunk
SVN_TAG.graphviz=	${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/graphviz

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
