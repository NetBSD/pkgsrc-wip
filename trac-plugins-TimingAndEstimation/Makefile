# $NetBSD: Makefile,v 1.1.1.1 2009/03/16 18:55:08 lexort Exp $

SVNVERSION=	5162
VERSION=	0.7.6.${SVNVERSION}
DISTNAME=	TracTimingAndEstimation-${VERSION}
PKGNAME=	trac-plugins-TimingAndEstimation-${VERSION}
# Empty to avoid default setting.
PKGREVISION=
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/TimingAndEstimationPlugin
COMMENT=	Graphviz plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	plugin
SVN_ROOT.plugin=	http://trac-hacks.org/svn/timingandestimationplugin/branches/trac0.11
SVN_TAG.plugin=		${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/plugin

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
