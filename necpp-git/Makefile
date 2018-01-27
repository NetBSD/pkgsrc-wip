# $NetBSD: Makefile,v 1.3 2014/06/15 02:02:05 makoto Exp $

DISTNAME=		necpp-git-1
CATEGORIES=		news
MASTER_SITES=		https://github.com/tmolteno/necpp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/tmolteno/necpp/
COMMENT=		C++ rewrite of the Numerical Electromagnetics Code
LICENSE=		gnu-gpl-v2

GIT_REPOSITORIES=	necpp
GIT_REPO.necpp=		git://github.com/tmolteno/necpp.git
WRKSRC=			${WRKDIR}/necpp

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-lapack

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		automake autoreconf gmake
MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		test
SUBST_FILES.test=	configure
SUBST_SED.test=		-e '/test/s/ == / = /'
SUBST_MESSAGE.test=	** Pre-edit to avoid check-portability.awk flags
SUBST_STAGE.test=	pre-configure

post-patch:
	cd ${WRKSRC} && make -f Makefile.git

#.include "../../math/lapack/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
