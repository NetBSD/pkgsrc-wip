# $NetBSD: Makefile,v 1.11 2015/08/04 20:04:16 thomasklausner Exp $

SVNREV=		9935
DISTNAME=	TracSpamFilter-0.3.2dev
EGG_NAME=	${DISTNAME}_r0
PKGNAME=	trac-plugins-spamfilter-0.3.2pre${SVNREV}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/SpamFilter
COMMENT=	Spam Filter plugin for Trac

DEPENDS+=	trac>=0.12:../../www/trac

PYTHON_VERSIONED_DEPENDENCIES=	dns

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.3.2dev/9935

SVN_REPOSITORIES=	spamfilter
SVN_ROOT.spamfilter=	http://svn.edgewall.org/repos/trac/plugins/0.12/spam-filter-captcha
SVN_TAG.spamfilter=	${SVNREV}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/spamfilter

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
