# $NetBSD: Makefile,v 1.1.1.1 2009/02/24 20:52:04 lexort Exp $

DISTNAME=	TracGraphViz-2.1.3.5305
PKGNAME=	trac-plugins-GraphViz-2.1.3.5305
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/GraphVizPlugin
COMMENT=	Graphviz plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

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
