# $NetBSD: Makefile,v 1.3 2005/06/12 23:51:17 kristerw Exp $
#

DISTNAME=	 	EMBOSS-2.9.0
PKGNAME=		emboss-java-0.0.3
CATEGORIES=		biology
MASTER_SITES		ftp://ftp.uk.embnet.org/pub/EMBOSS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.emboss.org
COMMENT=		interface between emboss and jemboss

DEPENDS+=		emboss-base-2.9.0:../../wip/emboss-base
DEPENDS+=		cross-i386-linux>=2.0.7.1:../../cross/i386-linux
DEPENDS+=		cross-binutils>=2.15.0.0:../../cross/binutils

#also need java installed
#setenv PKG_JAVA_HOME <pkgdir>/java/sun-<version>
#setenv CROSS_PKG i386-linux


WRKSRC=			${WRKDIR}/${DISTNAME}
USE_JAVA=		YES
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
NO_CONFIGURE=		YES
USE_CROSS_BINUTILS=	YES
CHECK_SHLIBS=		NO

DIST_SUBDIR=		emboss/emboss-2.9.0

CONF_ARGS+=	--with-java=${PKG_JAVA_HOME}/include
CONF_ARGS+=	--with-javaos=${PKG_JAVA_HOME}/include/linux
CONF_ARGS+=	--bindir=${PREFIX}/bin
CONF_ARGS+=	--libdir=${PREFIX}/lib
CONF_ARGS+=	--x-libraries=${PREFIX}/emul/linux/usr/X11R6/lib/
CONF_ARGS+=	--host=i386-linux
CONF_ARGS+=	--build=i386-netbsd
CONF_ARGS+=	--prefix=${PREFIX}/cross/i386-linux/

post-patch:
	${SED} -e 's:@CROSSPKG@:${PREFIX}/cross/i386-linux/lib:' \
		${WRKSRC}/ajax/Makefile.in > \
		${WRKSRC}/ajax/Makefile.in.bak
	${MV} ${WRKSRC}/ajax/Makefile.in.bak \
		${WRKSRC}/ajax/Makefile.in

do-build:
	CROSS_PKG=i386-linux export CROSS_PKG; && cd ${WRKSRC} && ${PREFIX}/bin/cross-env ./configure ${CONF_ARGS}
	CROSS_PKG=i386-linux export CROSS_PKG; && cd ${WRKSRC}/ajax && ${PREFIX}/bin/cross-env make


do-install:
	${CP} ${WRKSRC}/ajax/.libs/libajax.so.0.1.0 ${WRKSRC}/ajax/.libs/libajaxj.so
	${CP} ${WRKSRC}/ajax/.libs/libajaxj.so ${PREFIX}/lib/libajaxj.so
	${CP} ${WRKSRC}/ajax/.libs/libajax.a ${WRKSRC}/ajax/.libs/libajaxj.a
	${CP} ${WRKSRC}/ajax/.libs/libajaxj.a ${PREFIX}/lib/libajaxj.a
	${CP} ${WRKSRC}/ajax/.libs/libajax.la ${WRKSRC}/ajax/.libs/libajaxj.la
	${CP} ${WRKSRC}/ajax/.libs/libajaxj.la ${PREFIX}/lib/libajaxj.la



.include "../../wip/emboss-base/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
