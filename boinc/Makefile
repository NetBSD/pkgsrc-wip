# $NetBSD: Makefile,v 1.3 2010/04/30 10:29:17 asau Exp $

DISTNAME=		boinc-6.10.50
CATEGORIES=		parallel
MASTER_SITES=		http://boinc.berkeley.edu/ # stub
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://boinc.berkeley.edu/
COMMENT=		Middleware system for volunteer and grid computing

PKG_DESTDIR_SUPPORT=	user-destdir

# Get it from Subversion repository:
SVN_REPOSITORIES=	boinc
SVN_ROOT.boinc=		http://boinc.berkeley.edu/svn/tags/boinc_core_release_6_10_50
SVN_MODULE.boinc=	boinc
# more at http://boinc.berkeley.edu/trac/wiki/SourceCode

WRKSRC=			${WRKDIR}/$(SVN_MODULE.boinc)

CHECK_PORTABILITY_SKIP=	client/scripts/.svn/text-base/boinc-client.in.svn-base \
			client/scripts/boinc-client.in

GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake pkg-config # gmake gm4
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} _autosetup

.include "../../wip/mk/svn-package.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
