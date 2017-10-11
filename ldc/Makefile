# $NetBSD$

PKGNAME=	ldc-0.17.0
PKGREVISION=	1
DISTNAME=	${PKGNAME_NOREV}-src
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ldc-developers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ldc-developers/ldc/
COMMENT=	D compiler based on LLVM
LICENSE=	modified-bsd					\
		AND (artistic OR gnu-gpl-v1)			\
		AND (artistic OR gnu-gpl-v2 OR gnu-gpl-v3)	\
		AND gnu-lgpl-v2.1				\
		AND modified-bsd				\
		AND boost-license
#TODO: The modified-bsd two lines above should be
# University of Illinois Open Source License.
# They are similar, but I am not sure if they are equivalent.

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DLLVM_CONFIG=${LLVM_CONFIG_PATH}

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/ldc2.conf ${PKG_SYSCONFDIR}/ldc2.conf

post-install:
	${MKDIR} -p ${DESTDIR}${EGDIR}	\
		&& ${MV} ${DESTDIR}${PREFIX}/etc/ldc2.conf	\
			${DESTDIR}${EGDIR}
	${RM} ${DESTDIR}${PREFIX}/include/d/core/runtime.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/config.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/errno.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/fenv.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/locale.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/math.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/stdio.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/stdlib.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/string.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/tgmath.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/stdc/time.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/dlfcn.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/execinfo.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/cdefs.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/elf.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/elf32.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/elf64.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/elf_common.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/event.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/link_elf.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/sys/mman.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/netbsd/time.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/arpa/inet.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/dirent.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/dlfcn.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/fcntl.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/grp.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/net/if_.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/netdb.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/netinet/in_.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/netinet/tcp.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/poll.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/pthread.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/pwd.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sched.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/semaphore.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/setjmp.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/signal.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/stdio.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/stdlib.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/ioctl.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/ipc.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/mman.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/resource.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/select.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/shm.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/socket.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/stat.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/time.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/types.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/uio.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/un.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/utsname.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/sys/wait.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/syslog.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/termios.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/time.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/ucontext.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/unistd.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/sys/posix/utime.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/thread.d.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/threadasm.S.orig
	${RM} ${DESTDIR}${PREFIX}/include/d/core/time.d.orig

.include "../../wip/libLLVM38/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
