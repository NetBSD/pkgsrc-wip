# $NetBSD: Makefile,v 1.25 2009/03/08 15:57:25 asau Exp $
#

DISTNAME=		ecl-8.12.0
PKGNAME=		ecl-9.2.99
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://ecls.sourceforge.net/
COMMENT=		Embeddable Common Lisp

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

CVS_REPOSITORIES=	ecl
CVS_PROJECT=		ecls
CVS_ROOT.ecl=		${CVS_ROOT_SOURCEFORGE}
CVS_MODULE.ecl=		ecl

# CVS_REPOSITORIES+=	ecl-test
# CVS_ROOT.ecl-test=	${CVS_ROOT_SOURCEFORGE}
# CVS_MODULE.ecl-test=	ecl-test

WRKSRC=			${WRKDIR}/ecl

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system
CONFIGURE_ENV+=		ECL_BOEHM_GC_HEADER=gc/gc.h
CONFIGURE_ARGS+=	--with-system-gmp

# Change package version to make it differ from released one:
SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	post-patch
SUBST_MESSAGE.fix-version=	Fixing package version.
SUBST_FILES.fix-version=	src/configure.in
SUBST_SED.fix-version=		-e '/^AC_INIT(\[ecl\],/s/\[\([0-9.]*\)\]/[${PKGVERSION_NOREV}]/'

PLIST_SUBST=	PKGVERSION_MAJOR_MINOR=${PKGVERSION_NOREV:R} PKGVERSION_MAJOR=${PKGVERSION_NOREV:R:R}

# Make package version change to come in effect:
USE_TOOLS+=		autoconf
pre-configure:
	cd ${WRKSRC}/src && autoconf

# Work around problem with libraries on "Darwin 8.11.0 Power Macintosh":
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=    yes
.endif

.include "../../wip/mk/cvs-package.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
