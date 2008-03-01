# $NetBSD: Makefile,v 1.1.1.1 2008/03/01 11:31:59 asau Exp $
#

DISTNAME=		open-axiom-1.1.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=open-axiom/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.open-axiom.org/
# http://open-axiom.sourceforge.net/index.html
COMMENT=		Platform for symbolic, algebraic, and numerical computations

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gawk makeinfo
USE_LANGUAGES+=		fortran
BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb
#INFO_FILES=		yes

USE_GNU_CONFIGURE_HOST=	no

#TARGET_SYSTEM!=		../../mk/gnu-config/config.guess
#PLIST_SUBST+=		TARGET_SYSTEM=${TARGET_SYSTEM}

# The only officially supported for now, GCL:
#BUILD_DEPENDS+=		gcl>=2.6.7:../../lang/gcl
CONFIGURE_ARGS+=	--with-lisp=clisp --with-x=no
CONFIGURE_ARGS+=	AXIOM_LISP=/usr/pkg/bin/clisp
CONFIGURE_ENV+=		AXIOM_LISP=/usr/pkg/bin/clisp
#BUILD_DEPENDS+=	clisp>=2.41:../../lang/clisp
#CONFIGURE_ARGS+=	--with-lisp=sbcl --with-x=no

# I need to figure out, why it fails with pkgsrc's version:
do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS} # --prefix=/usr/pkg

.include "../../mk/bsd.pkg.mk"
