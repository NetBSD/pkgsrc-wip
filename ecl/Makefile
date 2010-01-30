# $NetBSD: Makefile,v 1.33 2010/01/30 20:14:08 asau Exp $
#

DISTNAME=		ecl-9.12.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://ecls.sourceforge.net/
COMMENT=		Embeddable Common Lisp
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system --with-system-gmp

.include "options.mk"

PLIST_SUBST=	PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV:R} \
		PKGVERSION_MAJOR=${PKGVERSION_NOREV:R:R}

## CVS part:

PKGNAME=		ecl-9.12.99
WRKSRC=			${WRKDIR}/ecl

CVS_REPOSITORIES=	ecl
CVS_PROJECT=		ecls
CVS_ROOT.ecl=		${CVS_ROOT_SOURCEFORGE}
CVS_MODULE.ecl=		ecl

# CVS_REPOSITORIES+=	ecl-test
# CVS_ROOT.ecl-test=	${CVS_ROOT_SOURCEFORGE}
# CVS_MODULE.ecl-test=	ecl-test

# Change package version to make it differ from released one:
SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	post-patch
SUBST_MESSAGE.fix-version=	Fixing package version.
SUBST_FILES.fix-version=	src/configure.in
SUBST_SED.fix-version=		-e '/^AC_INIT(\[ecl\],/s/\[\([0-9.]*\)\]/[${PKGVERSION_NOREV}]/'

SUBST_CLASSES+=			fix-libdir
SUBST_STAGE.fix-libdir=		post-patch
SUBST_MESSAGE.fix-libdir=	Fixing package version.
SUBST_FILES.fix-libdir=		src/configure.in
SUBST_SED.fix-libdir=		-e '/^ecldir=/s|^.*$$|ecldir="$${libdir}/${PKGNAME_NOREV}"|'

# Make package version change to come in effect:
USE_TOOLS+=		autoconf
pre-configure:
	cd ${WRKSRC}/src && autoconf

.include "../../wip/mk/cvs-package.mk"
## End of CVS part
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
