# $NetBSD: Makefile,v 1.1.1.1 2008/01/10 21:05:04 asau Exp $
#

DISTNAME=		fricas-1.0.1-full
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fricas.sourceforge.net/index.html
COMMENT=		FriCAS is an advanced computer algebra system.

#WRKSRC=			${WRKDIR}/${DISTNAME}-build/

#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
#HAS_CONFIGURE=		yes
#USE_LIBTOOL=		yes
#CONFIGURE_SCRIPT=	../${DISTNAME}/src/configure
USE_TOOLS+=		gmake gawk makeinfo
#INFO_FILES=		yes

USE_GNU_CONFIGURE_HOST=	no
CONFIGURE_ARGS+=	--with-lisp=clisp --with-x=no
#CONFIGURE_ARGS+=	--with-lisp=sbcl --with-x=no

USE_DESTDIR=		full
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

# I need to figure out, why it fails with pkgsrc's version:
do-configure:
	cd ${WRKSRC} && ./configure ${CONFIGURE_ARGS}

# I need to figure out, why it doesn't install that file,
# it ends in endless loop trying to exec that "viewman" file:
post-install:
	echo exit 0 > ${DESTDIR}${PREFIX}/lib/axiom/target/${MACHINE_ARCH}-unknown-${LOWER_OPSYS}elf${OS_VERSION}/lib/viewman
	chmod +x ${DESTDIR}${PREFIX}/lib/axiom/target/${MACHINE_ARCH}-unknown-${LOWER_OPSYS}elf${OS_VERSION}/lib/viewman

.include "../../mk/bsd.pkg.mk"
