# $NetBSD: Makefile,v 1.5 2009/03/24 16:29:50 lexort Exp $

SVNVERSION=	5370
VERSION=	0.7.6.${SVNVERSION}
DISTNAME=	TracTimingAndEstimation-${VERSION}
PKGNAME=	trac-plugins-TimingAndEstimation-${VERSION}
# Empty to avoid default setting.
PKGREVISION=	0
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/TimingAndEstimationPlugin
COMMENT=	TimingAndEstimation plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	plugin
SVN_ROOT.plugin=	http://trac-hacks.org/svn/timingandestimationplugin/branches/trac0.11
SVN_TAG.plugin=		${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/plugin

# Bogus, but needed because setup runs as root during build.
PRIVILEGED_STAGES+=	clean

REPLACE_PYTHON=	scripts/trac-post-commit.py

EGDIR=		share/examples/trac

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/trac-post-commit.py ${DESTDIR}${PREFIX}/${EGDIR}/TimingAndEstimation-post-commit.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
