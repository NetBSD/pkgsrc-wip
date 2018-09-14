# $NetBSD$

DISTNAME=	rust-1.29.0
PKGNAME=	${DISTNAME:S/rust/rust-bin/}
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

CONFLICTS=	rust-[0-9]*

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-x86_64 Linux-*-* NetBSD-*-x86_64

USE_TOOLS+=	bash
WRKSRC=		${WRKDIR}/${DISTFILES:S/.tar.gz//}

PLIST_SRC=	${PKGDIR}/PLIST.common
PLIST_SRC+=	${WRKDIR}/PLIST.lib
PLIST_SUBST+=	RUST_ARCH=${RUST_ARCH}

INSTALLATION_DIRS=	bin ${PKGMANDIR} share/doc/cargo/bash_completion.d

.include "../../mk/bsd.prefs.mk"

DISTFILES:=	# empty

.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	i686-apple-darwin
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-apple-darwin
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-freebsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-i386) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	i686-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-aarch64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-powerpc64le) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	powerpc64le-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-netbsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif

do-build:
	cd ${WRKSRC}/rustc && ls lib/lib* > ${WRKDIR}/PLIST.lib
	cd ${WRKSRC}/rust-analysis-${RUST_ARCH} && \
	ls lib/rustlib/${RUST_ARCH}/analysis/* \
		>> ${WRKDIR}/PLIST.lib
	cd ${WRKSRC}/rust-std-${RUST_ARCH} && \
	ls lib/rustlib/${RUST_ARCH}/lib/* \
		>> ${WRKDIR}/PLIST.lib

do-install:
	cd ${WRKSRC} && env PKGMANDIR=${PKGMANDIR} bash ./install.sh \
	--destdir=${DESTDIR} --prefix=${PREFIX}

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in rls rustc rustdoc
	otool -XL ${DESTDIR}${PREFIX}/bin/${bin}			\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/bin/${bin};			\
	done
.  endfor
.endif

.include "../../mk/bsd.pkg.mk"
