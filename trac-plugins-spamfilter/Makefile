# $NetBSD: Makefile,v 1.8 2012/11/03 19:41:30 kristerw Exp $

SVNREV=		9935
DISTNAME=	TracSpamFilter-0.3.2dev
PKGNAME=	trac-plugins-spamfilter-0.3.2pre${SVNREV}
PKGREVISION=	1
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/SpamFilter
COMMENT=	Spam Filter plugin for Trac

DEPENDS+=	{ja-,}trac>=0.12:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

SVN_REPOSITORIES=	spamfilter
SVN_ROOT.spamfilter=	http://svn.edgewall.org/repos/trac/plugins/0.12/spam-filter-captcha
SVN_TAG.spamfilter=	${SVNREV}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/spamfilter

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
