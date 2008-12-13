# $NetBSD: Makefile,v 1.20 2008/12/13 02:43:53 asau Exp $
#

DISTNAME=		ecl-8.12.0
PKGNAME=		ecl-8.12.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

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

# sys/wait.h isn't detected on NetBSD:
USE_TOOLS+=		autoconf
post-extract:
	cd ${WRKSRC}/src && autoconf

.include "../../wip/mk/cvs-package.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
