# $NetBSD$

DISTNAME=	netty-4.1.53.Final
PKGNAME=	java-${DISTNAME:S/.Final//}
CATEGORIES=	java devel
MASTER_SITES=	http://dl.bintray.com/netty/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://netty.io/
COMMENT=	Asynchronous event-driven network application framework and tools
LICENSE=	apache-2.0

JAR=		${PKG_JAVA_HOME}/bin/jar

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "aarch64"
NETTY_ARCH=	aarch_64
.elif ${MACHINE_ARCH} == "amd64"
NETTY_ARCH=	x86_64
.elif ${MACHINE_ARCH} == "i386"
NETTY_ARCH=	x86_32
.else
NETTY_ARCH=	${MACHINE_ARCH}
.endif

post-extract:
	${RUN} cd ${WRKSRC} && \
		${JAR} xf jar/netty-transport-native-kqueue-${PKGVERSION_NOREV}.Final-sources.jar
	${RUN} cd ${WRKSRC} && \
		${JAR} xf jar/netty-transport-native-unix-common-${PKGVERSION_NOREV}.Final-sources.jar
	${RUN} cd ${WRKSRC} && cat ${FILESDIR}/patch-netty_kqueue_bsdsocket.c | patch -p0

CFLAGS+=	-D_POSIX_C_SOURCE=200112L -D_NETBSD_SOURCE
CFLAGS+=	-I${PKG_JAVA_HOME}/include
CFLAGS+=	-I${PKG_JAVA_HOME}/include/${LOWER_OPSYS}

NETTY_UNIX_COMMON_SRCS=	netty_unix_buffer.c netty_unix_errors.c \
			netty_unix_filedescriptor.c netty_unix_limits.c \
			netty_unix_socket.c netty_unix_util.c
NETTY_KQUEUE_SRCS=	netty_kqueue_bsdsocket.c netty_kqueue_eventarray.c \
			netty_kqueue_native.c
NETTY_SRCS=		${NETTY_UNIX_COMMON_SRCS} ${NETTY_KQUEUE_SRCS}
NETTY_LOS=		${NETTY_SRCS:S/.c$/.lo/}

do-build:
.for f in ${NETTY_SRCS}
	${RUN} cd ${WRKSRC} && \
		 ${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} -c ${f}
.endfor
	${RUN} cd ${WRKSRC} && \
		${LIBTOOL} --mode=link --tag=CC ${CC} \
			-avoid-version ${LDFLAGS} \
                        -o libnetty_transport_native_kqueue_${NETTY_ARCH}.la \
			${NETTY_LOS} -rpath ${PREFIX}/lib

INSTALLATION_DIRS=	lib/java

do-install:
	${RUN} cd ${WRKSRC} && \
		${LIBTOOL} --mode=install ${INSTALL_LIB} \
			-c libnetty_transport_native_kqueue_${NETTY_ARCH}.la \
			${DESTDIR}${PREFIX}/lib/libnetty_transport_native_kqueue_${NETTY_ARCH}.la
	${MKDIR} ${WRKSRC}/jar/all-in-one/META-INF/native
	${MV} ${DESTDIR}${PREFIX}/lib/libnetty_transport_native_kqueue_${NETTY_ARCH}.so \
		${WRKSRC}/jar/all-in-one/META-INF/native
	${RUN} cd ${WRKSRC}/jar/all-in-one && \
		${JAR} uvf netty-all-${PKGVERSION_NOREV}.Final.jar \
		META-INF/native/libnetty_transport_native_kqueue*.so
	${INSTALL_DATA} ${WRKSRC}/jar/all-in-one/netty-all-${PKGVERSION_NOREV}.Final.jar \
		${DESTDIR}${PREFIX}/lib/java/netty-${PKGVERSION_NOREV}.jar
	${LN} -nfs netty-${PKGVERSION_NOREV}.jar ${DESTDIR}${PREFIX}/lib/java/netty.jar
	${RM} -f ${DESTDIR}${PREFIX}/lib/libnetty_transport_native_kqueue_x86_64.*

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
