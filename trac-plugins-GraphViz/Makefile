# $NetBSD: Makefile,v 1.5 2012/10/07 17:17:46 asau Exp $

SVNVERSION=	4543
UPSTREAM_VERSION=	0.7.5
VERSION=	${UPSTREAM_VERSION=}.${SVNVERSION}
DISTNAME=	TracGraphViz-${VERSION}
PKGNAME=	trac-plugins-GraphViz-${VERSION}
# Empty to avoid default setting.
PKGREVISION=	1
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/GraphVizPlugin
COMMENT=	Graphviz plugin for Trac

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

EGG_NAME=	graphviz-${UPSTREAM_VERSION}dev

SVN_REPOSITORIES=	plugin
SVN_ROOT.plugin=	http://trac-hacks.org/svn/graphvizplugin/0.11
SVN_TAG.plugin=	5305

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/plugin

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
