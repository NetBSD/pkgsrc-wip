# $NetBSD: Makefile,v 1.10 2008/03/05 16:16:43 tnn2 Exp $
#

DISTNAME=		${PKGNAME}-full
PKGNAME=		fricas-1.0.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake # gawk makeinfo

SUBST_CLASSES+=		fix-awk
SUBST_STAGE.fix-awk=	pre-configure
SUBST_MESSAGE.fix-awk=	Fixing location of awk interpreter in scripts.
SUBST_FILES.fix-awk=	src/hyper/search.pamphlet
SUBST_SED.fix-awk=	-e 's,/bin/awk,${AWK},g'

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
