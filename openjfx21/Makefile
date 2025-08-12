# $NetBSD$

DISTNAME=	jfx21u-21.0.8+2
PKGNAME=	${DISTNAME:S/jfx21u-/openjfx21-/:C/\\+[[:digit:]\.]*//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=openjdk/}
GITHUB_PROJECT=	jfx21u
GITHUB_TAG=	21.0.8+2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/openjdk/jfx21u/
COMMENT=	JavaFX is Java client application platform
LICENSE=	gnu-gpl-v2

JARS+=		lucene-core-7.7.3.jar
JARS+=		lucene-grouping-7.7.3.jar
JARS+=		lucene-queryparser-7.7.3.jar
JARS+=		antlr4-4.7.2-complete.jar

DISTFILES=	${DEFAULT_DISTFILES} ${JARS}

SITES.lucene-core-7.7.3.jar=		https://repo.maven.apache.org/maven2/org/apache/lucene/lucene-core/7.7.3/
SITES.lucene-grouping-7.7.3.jar=	https://repo.maven.apache.org/maven2/org/apache/lucene/lucene-grouping/7.7.3/
SITES.lucene-queryparser-7.7.3.jar=	https://repo.maven.apache.org/maven2/org/apache/lucene/lucene-queryparser/7.7.3/
SITES.antlr4-4.7.2-complete.jar=	https://repo1.maven.org/maven2/org/antlr/antlr4/4.7.2/

DEPENDS+=	swt-[0-9]*:../../x11/swt

WRKSRC=		${WRKDIR}/jfx21u-21.0.8-2
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	modules/javafx.web/src/main/native/Source/JavaScriptCore/javascriptcoregtk.pc.in

USE_JAVA=	yes
USE_JAVA2=	21

TOOL_DEPENDS+=	gradle-[0-9]*:../../devel/gradle
MAKE_ENV+=	GRADLE_USER_HOME=${WRKDIR}/.gradle

# Should use pkg-config for libX11 inside gradle instead.
CXX_LDFLAGS+=		-L${PREFIX}/lib
CXX_LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
_WRAP_EXTRA_ARGS.CXX+=	${CXX_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${CXX_LDFLAGS}

# For pipewire header file
CC_CPPFLAGS+=	-I${BUILDLINK_DIR}/include/pipewire-0.3
CC_CPPFLAGS+=	-I${BUILDLINK_DIR}/include/spa-0.2
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
CC_CPPFLAGS+=	-D__LOCALE_C_ONLY
.endif
_WRAP_EXTRA_ARGS.CC+=	${CC_CPPFLAGS}
CWRAPPERS_PREPEND.cc+=	${CC_CPPFLAGS}

post-patch:
	# Do not verify swt jar.
	${RM} ${WRKSRC}/gradle/verification-metadata.xml
	# build file for NetBSD
	${CP} ${FILESDIR}/netbsd.gradle ${WRKSRC}/buildSrc
	# Gstreamer build for NetBSD
	${CP} -r ${WRKSRC}/modules/javafx.media/src/main/native/jfxmedia/projects/linux \
		${WRKSRC}/modules/javafx.media/src/main/native/jfxmedia/projects/netbsd
	${CP} -r ${WRKSRC}/modules/javafx.media/src/main/native/gstreamer/projects/linux \
		${WRKSRC}/modules/javafx.media/src/main/native/gstreamer/projects/netbsd

pre-configure:
	${MKDIR} ${WRKDIR}/deps
	${LN} -sf ${PREFIX}/lib/java/swt.jar \
	${WRKDIR}/deps/org.eclipse.swt.gtk.netbsd.x86_64_3.105.3.v20170228-0512.jar
.for d in ${JARS}
	${LN} -sf ${WRKDIR}/${d} ${WRKDIR}/deps
.endfor

do-configure:
	${ECHO} "JFX_DEPS_URL = ${WRKDIR}/deps" >> ${WRKSRC}/gradle.properties

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} gradle --no-daemon all \
			--exclude-task javadoc --warning-mode all --info

INSTALLATION_DIRS+=     openjfx21/lib
INSTALLATION_DIRS+=     openjfx21/jmods

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/javafx-exports.zip \
		${DESTDIR}${PREFIX}/openjfx21
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/javafx-sdk-21*/lib/* \
		${DESTDIR}${PREFIX}/openjfx21/lib
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/javafx-sdk-21*/src.zip \
		${DESTDIR}${PREFIX}/openjfx21
	${INSTALL_DATA} ${WRKSRC}/build/artifacts/javafx-jmods-21*/* \
		${DESTDIR}${PREFIX}/openjfx21/jmods

.include "../../lang/openjdk21/buildlink3.mk"
.include "../../multimedia/pipewire/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
