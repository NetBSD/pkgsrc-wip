# $NetBSD: Makefile,v 1.3 2004/07/02 17:48:17 blef Exp $
#

DISTNAME=	java-gtk-0.8.1
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=java-gnome/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://java-gnome.sourceforge.net/
COMMENT=	JAVA Bindings for GTK+2

DEPENDS+=	apache-ant>=1.6.1:../../devel/apache-ant
DEPENDS+=	jikes-[0-9]*:../../lang/jikes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 kaffe
PKG_JVM_DEFAULT=	kaffe

CONFIGURE_ARGS+=	--with-gtk-only
CONFIGURE_ARGS+=	--with-java-prefix=${PKG_JAVA_HOME}
CONFIGURE_ENV+=		JAVAC=${PREFIX}/bin/jikes
MAKE_ENV+=		JAVAC=${PREFIX}/bin/jikes

EGDIR=			${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

.if defined(PKG_JVM) && !empty(PKG_JVM:Mkaffe*)
CONFIGURE_ARGS+=	--with-kaffe
.endif

post-configure:
.for f in Makefile* classes .cvs*
	${RM} -rf ${WRKSRC}/test/${f}
.endfor

# jni.h and friends
post-buildlink:
	cd ${PKG_JAVA_HOME}/include && ${PAX} -rwppm . \
	    ${BUILDLINK_DIR}/include

# No idea why doesn't work by the normal method...
do-build:
	cd ${WRKSRC} && ${GMAKE} -C src gtk

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/lib* ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${PREFIX}/share/classpath
	${FIND} ${WRKSRC}/test -name CVS | ${XARGS} ${RM} -rf
	cd ${WRKSRC}/test && ${PAX} -rwppm . ${EGDIR}

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
