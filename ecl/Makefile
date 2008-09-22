# $NetBSD: Makefile,v 1.17 2008/09/22 19:37:36 asau Exp $
#

DISTNAME=		ecl-8.9.0
PKGNAME=		ecl-8.9.0
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://ecls.sourceforge.net/
COMMENT=		Embeddable Common Lisp

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

CVS_REPOSITORIES=	ecls
CVS_PROJECT=		ecls
CVS_ROOT.ecls=		${CVS_ROOT_SOURCEFORGE}
CVS_MODULE.ecls=	ecl

WRKSRC=			${WRKDIR}/ecls

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system
CONFIGURE_ENV+=		ECL_BOEHM_GC_HEADER=gc/gc.h
CONFIGURE_ARGS+=	--with-system-gmp

.include "../../wip/mk/cvs-package.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
