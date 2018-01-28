# $NetBSD: Makefile,v 1.10 2012/10/01 21:43:23 asau Exp $
#

DISTNAME=		EMBOSS-2.9.0
PKGNAME=		jemboss-standalone-2.9.0
PKGREVISION=		1
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.uk.embnet.org/pub/EMBOSS/old/2.9.0/

MAINTAINER=	dprice@cs.nmsu.edu
HOMEPAGE=	http://www.emboss.org/
COMMENT=	Standalone Interface for EMBOSS

DEPENDS+=	emboss-java>=0.0.3:../../wip/emboss-java
#DEPENDS+=	jakarta-servletapi-[0-9]*:../../www/jakarta-servletapi
DEPENDS+=	xerces-j>=1.2.0:../../textproc/xerces-j
#DEPENDS+=	iasp>=2.1.1:../../www/iasp
DEPENDS+=	apache-ant>=1.5.3.1:../../devel/apache-ant

DIST_SUBDIR=		emboss/emboss-2.9.0


PKG_DEFAULT_JVM=	sun-jdk13

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_JAVA=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-java=${PKG_JAVA_HOME}/include
CONFIGURE_ARGS+=	--with-javaos=${PKG_JAVA_HOME}/include/netbsd
CONFIGURE_ARGS+=	--with-thread=linux

post-extract:
	${CP} ${FILESDIR}/jemboss ${WRKSRC}/jemboss/

pre-configure:
	${SED} -e 's:@PKG_JAVA_HOME@:${PKG_JAVA_HOME}:' \
	       -e 's:@PREFIX@:${PREFIX}:' \
		${WRKSRC}/jemboss/utils/install-jemboss-server.sh > \
		${WRKSRC}/jemboss/utils/install-jemboss-server.sh.bak
	${MV} ${WRKSRC}/jemboss/utils/install-jemboss-server.sh.bak \
		${WRKSRC}/jemboss/utils/install-jemboss-server.sh
	${SED} -e 's|@JAVA_CLASSPATH@|${CLASSPATH}|' \
	       -e 's|@JAVA@|${PKG_JAVA_HOME}/bin|' \
	       -e 's|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/jemboss/runJemboss.sh > \
		${WRKSRC}/jemboss/runJemboss.sh.bak
	${SED}  -e 's|share\/EMBOSS\/jemboss|share\/EMBOSS|' \
		${WRKSRC}/jemboss/runJemboss.sh.bak > \
		${WRKSRC}/jemboss/runJemboss.sh.bak1
	${MV} ${WRKSRC}/jemboss/runJemboss.sh.bak1 \
		${WRKSRC}/jemboss/runJemboss.sh
	${SED}  -e 's|share/EMBOSS/bin|pkg/bin|' \
		-e 's|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/jemboss/resources/jemboss.properties > \
	        ${WRKSRC}/jemboss/resources/jemboss.properties.bak
	${MV} ${WRKSRC}/jemboss/resources/jemboss.properties.bak \
		${WRKSRC}/jemboss/resources/jemboss.properties
	${SED} -e 's|@JAVAC@|${PKG_JAVA_HOME}/bin/javac|' \
	       -e 's|@X116@|-Wl,-R${X11BASE}/lib|' \
		${WRKSRC}/jemboss/Makefile.in > ${WRKSRC}/jemboss/Makefile.in.bak
	${SED}  -e 's|@EMBOSS_INSTALL@|${PREFIX}/share/EMBOSS/jemboss|' \
		 -e 's|javac org|javac -g org|' \
		${WRKSRC}/jemboss/jemboss > \
		${WRKSRC}/jemboss/jemboss.bak
	${MV}	${WRKSRC}/jemboss/jemboss.bak \
		${WRKSRC}/jemboss/jemboss
	${MV} ${WRKSRC}/jemboss/Makefile.in.bak ${WRKSRC}/jemboss/Makefile.in
	${SED} -e 's|@LIB@|-Wl,-R${PREFIX}/lib|' \
		${WRKSRC}/configure > ${WRKSRC}/configure.bak
	${MV} ${WRKSRC}/configure.bak ${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure

post-install:
	cd ${WRKSRC}/jemboss/utils && \
	${SH} install-jemboss-server.sh
	${INSTALL_SCRIPT} ${WRKSRC}/jemboss/jemboss ${PREFIX}/bin/jemboss

#	${MV} ${WRKSRC}/jemboss/lib/axis/axis.jar ${PREFIX}/lib/java/axis.jar
#	${MV} ${WRKSRC}/jemboss/lib/jsse.jar ${PKG_JAVA_HOME}/lib/jsse.jar
#	${MV} ${WRKSRC}/jemboss/lib/jalview.jar ${PKG}/share/EMBOSS/jemboss/lib/jalview.jar

.include "../../wip/emboss-base/buildlink3.mk"
.include "../../wip/jalview/buildlink3.mk"
.include "../../devel/pth/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

CLASSPATH:=	${PKG_JAVA_HOME}/lib/classes.zip:${PREFIX}/lib/java/ant.jar:${PKG_JAVA_HOME}/lib/jsse.jar:${PREFIX}/lib/java/xerces.jar:${PKG_JAVA_HOME}/lib/tools.jar:${PREFIX}/lib/java/jalview.jar:${PREFIX}/lib/java/servlet.jar:${PREFIX}/java/iasp21/lib/activation.jar:${PREFIX}/java/iasp21/lib/mail.jar:${CLASSPATH}
