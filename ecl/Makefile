# $NetBSD: Makefile,v 1.14 2008/08/12 19:30:04 asau Exp $
#

PKGNAME=		ecl-0.9.12
DISTNAME=		ecl-0.9l
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

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-boehm=system
CONFIGURE_ENV+=		ECL_BOEHM_GC_HEADER=gc/gc.h
CONFIGURE_ARGS+=	--with-system-gmp

post-extract:
	${RUN} ${MKDIR} ${WRKSRC}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
