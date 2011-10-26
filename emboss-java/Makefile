# $NetBSD: Makefile,v 1.7 2011/10/26 13:41:50 noud4 Exp $
#

DISTNAME=		EMBOSS-2.9.0
PKGNAME=		emboss-java-0.0.3
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.uk.embnet.org/pub/EMBOSS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://emboss.sourceforge.net/
COMMENT=		Interface between emboss and jemboss

DEPENDS+=		emboss-base>=2.9.0:../../wip/emboss-base

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_JAVA=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
HAS_CONFIGURE=		yes
CHECK_SHLIBS=		no
USE_LANGUAGES+=		c c++
DIST_SUBDIR=		emboss/emboss-2.9.0

CONFIGUE_ARGS+=	--with-java=${PKG_JAVA_HOME}/include
CONFIGUE_ARGS+=	--with-javaos=${PKG_JAVA_HOME}/include/netbsd
CONFIGUE_ARGS+=	--build=i386-netbsd
CONFIGUE_ARGS+=	--prefix=${PREFIX}

post-patch:
	${SED} -e 's:@CROSSPKG@:${PREFIX}/lib:' \
		${WRKSRC}/ajax/Makefile.in > \
		${WRKSRC}/ajax/Makefile.in.bak
	${MV} ${WRKSRC}/ajax/Makefile.in.bak \
		${WRKSRC}/ajax/Makefile.in

do-build:
	cd ${WRKSRC}/ajax && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	${CP} ${WRKSRC}/ajax/.libs/libajax.so.0.1.0 ${WRKSRC}/ajax/.libs/libajaxj.so
	${CP} ${WRKSRC}/ajax/.libs/libajaxj.so ${PREFIX}/lib/libajaxj.so
	${CP} ${WRKSRC}/ajax/.libs/libajax.a ${WRKSRC}/ajax/.libs/libajaxj.a
	${CP} ${WRKSRC}/ajax/.libs/libajaxj.a ${PREFIX}/lib/libajaxj.a
	${CP} ${WRKSRC}/ajax/.libs/libajax.la ${WRKSRC}/ajax/.libs/libajaxj.la
	${CP} ${WRKSRC}/ajax/.libs/libajaxj.la ${PREFIX}/lib/libajaxj.la

.include "../../wip/emboss-base/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
