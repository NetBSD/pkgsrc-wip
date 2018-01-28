# $NetBSD: Makefile,v 1.10 2014/11/02 09:31:17 makoto Exp $
#
DISTNAME=	swt-4.4-gtk-linux-x86
DISTNAME=	swt-4.4-gtk-linux-x86_64
PKGNAME=	java-swt-4.4
SHLIB_VERSION=	4427
CATEGORIES=	lang
MASTER_SITES=	http://download.eclipse.org/eclipse/downloads/drops4/R-4.4-201406061215/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/swt/
COMMENT=	Standard Widget Toolkit for Java
LICENSE=	eclipse-license

DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

WRKSRC=			${WRKDIR}/swt
USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 blackdown-jdk13 kaffe openjdk7
PKG_JVM_DEFAULT=	kaffe
USE_TOOLS=		gmake unzip

PLIST_SUBST+=	SHLIB_VERSION=${SHLIB_VERSION}

#SUBST_CLASSES+=	foo
#SUBST_STAGE.foo=	post-patch
#SUBST_FILES.foo=	make_gtk.mak
#SUBST_SED.foo=		-e s,@PKG_JVM_HOME@,${PKG_JAVA_HOME},

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	build.sh make_netbsd.mak
SUBST_SED.prefix=	-e s,@@PREFIX@@,${PREFIX},g

INSTALLATION_DIRS=	share/classpath
AUTO_MKDIRS=		yes

# (post-extract files)
#     19876 Jun  6 12:38 about.html
#       240 Nov  2 11:41 about_files
#   2028252 Jun  6 12:38 src.zip
#   2516821 Jun  6 12:37 swt-debug.jar
#   1903827 Jun  6 12:38 swt.jar

post-extract:
	cd ${WRKDIR} && \
	mkdir swt && cd swt ;\
	unzip ../src.zip >/dev/null 2>&1

do-build:
	cd ${WRKSRC} && ${SH} build.sh

do-install:
	${INSTALL_LIB} ${WRKSRC}/libswt-*gtk*.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKDIR}/*.jar ${DESTDIR}${PREFIX}/share/classpath

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
# ERROR: lib/libswt-glx-gtk-4427.so: missing library: libGL.so.2
# which is for X11_TYPE= native,
#.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
