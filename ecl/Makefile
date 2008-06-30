# $NetBSD: Makefile,v 1.13 2008/06/30 04:49:42 asau Exp $
#

PKGNAME=		ecl-0.9.99
DISTNAME=
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ecls/}

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
#CONFIGURE_SCRIPT=	../${DISTNAME}/src/configure
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system
CONFIGURE_ENV+=		ECL_BOEHM_GC_HEADER=gc/gc.h
CONFIGURE_ARGS+=	--with-system-gmp
#CONFIGURE_ARGS+=	--with-asdf --with-defsystem
#CONFIGURE_ARGS+=	--enable-threads

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../wip/mk/cvs-package.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
