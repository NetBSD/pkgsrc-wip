# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:23 thomasklausner Exp $

DISTNAME=		boinc-6.2.99
PKGREVISION=		1
CATEGORIES=		parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://boinc.berkeley.edu/
COMMENT=		Middleware system for volunteer and grid computing

PKG_DESTDIR_SUPPORT=	user-destdir

# Get it from Subversion repository:
SVN_REPOSITORIES=	boinc
SVN_ROOT.boinc=		http://boinc.berkeley.edu/svn/trunk/
SVN_MODULE.boinc=	boinc
# more at http://boinc.berkeley.edu/trac/wiki/SourceCode

WRKSRC=			${WRKDIR}/boinc

CHECK_PORTABILITY_SKIP=	boinc/client/scripts/.svn/text-base/boinc-client.in.svn-base \
			boinc/client/scripts/boinc-client.in

CONFIGURE_DIRS=		boinc
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf automake
USE_LANGUAGES=		c c++

pre-configure:
	${RUN} cd ${WRKSRC}/boinc && ${SH} _autosetup

.include "../../wip/mk/svn-package.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
