# $NetBSD: Makefile,v 1.12 2008/04/02 13:29:36 asau Exp $
#

DISTNAME=		fricas-1.0.99
PKGNAME=		${DISTNAME}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system

# Get it from Subversion repository:
SVN_REPOSITORIES=	fricas
SVN_ROOT.fricas=	https://fricas.svn.sourceforge.net/svnroot/fricas/trunk
SVN_MODULE.fricas=	fricas

WRKSRC=			${WRKDIR}/fricas

BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

SUBST_CLASSES+=		fix-awk
SUBST_STAGE.fix-awk=	pre-configure
SUBST_MESSAGE.fix-awk=	Fixing location of awk interpreter in scripts.
SUBST_FILES.fix-awk=	src/hyper/search.pamphlet
SUBST_SED.fix-awk=	-e 's,/bin/awk,${AWK},g'

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "options.mk"

.include "../mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
