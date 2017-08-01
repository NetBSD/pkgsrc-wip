# $NetBSD: Makefile,v 1.4 2014/10/30 08:53:34 makoto Exp $
#

DISTNAME=	flexdock-1.2.4
CATEGORIES=	devel
MASTER_SITES=	http://forge.scilab.org/index.php/p/flexdock/downloads/get/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://flexdock.dev.java.net/
COMMENT=	Swing windowing and docking framework
LICENSE=	apache-2.0

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
USE_LANGUAGES=	# none
USE_JAVA=	run
AUTO_MKDIRS=	yes

INSTALLATION_DIRS= 			\
	lib/java/flexdock 		\
	lib/java/flexdock/lib		\
	lib/java/flexdock/lib/jmf	\
	lib/java/flexdock/lib/jmf/doc	\
	lib/java/flexdock/lib/jmf/lib	\
	share/examples/flexdock

JAR_FILES=				\
	build/flexdock-${PKGVERSION_NOREV}.jar	\
	build/flexdock-demo-${PKGVERSION_NOREV}.jar

LIB_FILES=				\
	lib/looks-2.1.1.jar		\
	lib/skinlf.jar

JMF_LIB_FILES=				\
	lib/jmf/lib/customizer.jar	\
	lib/jmf/lib/jmf.jar		\
	lib/jmf/lib/mediaplayer.jar	\
	lib/jmf/lib/multiplayer.jar	\
	lib/jmf/lib/jmf.properties

do-build:
	${MKDIR} ${WRKSRC}
	(cd  ${WRKSRC}; \
	ant dist; \
	ant jar )

do-install:
	(cd ${WRKSRC}; \
	for i in ${JAR_FILES} ;do \
	  ${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/lib/java/flexdock/${i}; done ; \
	for i in ${LIB_FILES} ;do \
	  ${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/lib/java/flexdock/lib/${i}; done;\
	for i in ${JMF_LIB_FILES} ;do \
	  ${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/lib/java/flexdock/lib/jmf/lib/${i}; done;\
	)
	# for example, math/scilab wants the name without version
	(cd ${DESTDIR}${PREFIX}/lib/java/; \
	  ${LN} -f flexdock/flexdock-${PKGVERSION_NOREV}.jar \
	        flexdock/flexdock.jar )

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
