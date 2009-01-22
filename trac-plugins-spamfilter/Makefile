# $NetBSD: Makefile,v 1.2 2009/01/22 09:54:37 rsmarples Exp $

DISTNAME=	TracSpamFilter-0.1dev
PKGNAME=	trac-plugins-spamfilter-0.1pre7539
PKGREVISION=	# blank on purpose even though pkglint moans
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/SpamFilter
COMMENT=	Spam Filter plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	spamfilter
SVN_ROOT.spamfilter=	http://svn.edgewall.com/repos/trac/sandbox/spam-filter
SVN_TAG.spamfilter=	7539

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/spamfilter

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
