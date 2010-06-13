# $NetBSD: Makefile,v 1.7 2010/06/13 22:47:09 thomasklausner Exp $
#

DISTNAME=	swt-2.1.3-linux-gtk
PKGNAME=	java-swt-2.1.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.eclipse.org/downloads/drops/R-2.1.3-200403101828/
EXTRACT_SUFX=	.zip

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.eclipse.org/swt/
COMMENT=	Standard Widget Toolkit for Java

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

WRKSRC=			${WRKDIR}
USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 blackdown-jdk13 kaffe
PKG_JVM_DEFAULT=	kaffe

UNZIP_BIN=	${LOCALBASE}/bin/unzip

post-extract:
	@cd ${WRKSRC} && \
	${UNZIP_BIN} swt-pisrc.zip >/dev/null 2>&1 && \
	${UNZIP_BIN} swtsrc.zip >/dev/null 2>&1

do-build:
	cd ${WRKSRC} && ${SH} build.sh

SUBST_CLASSES+=	    foo
SUBST_STAGE.foo=    post-patch
SUBST_FILES.foo=    make_gtk.mak
SUBST_SED.foo=	    -e s,@PKG_JVM_HOME@,${PKG_JAVA_HOME},

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath
	${INSTALL_DATA} ${WRKSRC}/libswt-*gtk*.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/*.jar ${PREFIX}/share/classpath

.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
