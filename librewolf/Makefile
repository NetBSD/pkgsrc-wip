# $NetBSD:$

FIREFOX_VER=		${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=		141.0
MOZ_BRANCH_MINOR=	

DISTNAME=	librewolf-${FIREFOX_VER}-1.source
PKGNAME=	${DISTNAME:S/.source//:S/-1$//}
CATEGORIES=	www
MASTER_SITES=	https://gitlab.com/api/v4/projects/32320088/packages/generic/librewolf-source/${FIREFOX_VER}-1/

NODEJSKIT=		nodejs-output-141.0.tgz
DISTFILES=		${DEFAULT_DISTFILES} ${NODEJSKIT}
SITES.${NODEJSKIT}=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mozilla.org/en-US/firefox/
COMMENT=	Web browser with support for extensions (version ${FIREFOX_VER:tu:C/\\.[[:digit:]\.]*//})
LICENSE=	mpl-1.1

# -------- BEFORE UPDATING THIS PACKAGE PLEASE READ & UNDERSTAND: -------
#
# This package works around a (stupid) build time dependency on nodejs
# (which is not available for all architectures and unnecessary for the
# real build). To do this, it places some additional burden on the
# maintainer.
#
# While working on the package, please make sure you have
#
#	FIREFOX_MAINTAINER=yes
#
# set in your build environment.
# When the package is ready for commit (but before commit), do:
#
#	make maintainer-files
#
# This will do another round (depending on state of your work dir at this
# moment) of one or two builds and generate a cache of all output that
# nodejs generates during a build.
#
# When this is done, just commit the results (they will be in the files/
# directory).
#
# -----------------------------------------------------------------------

WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}

MOZILLA_DIR=	# empty

# Note: In --enable-chrome-format=flat case,
#       when updating remember to conditionalise about-background.png in PLIST
CONFIGURE_ARGS+=	--enable-application=browser

#CFLAGS+=	-I${PREFIX}/include/nspr
# for lang/gcc6
CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
# Do not use uselocale() in third_party/pipewire.
CFLAGS.NetBSD+=	-D__LOCALE_C_ONLY

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.DragonFly+=	-lplc4 -lnspr4
LDFLAGS.FreeBSD+=	-lplc4 -lnspr4
LDFLAGS.Linux+=		-lnspr4
LDFLAGS.SunOS+=		-lm

# Should revisit to complete mprotect support.
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/librewolf
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/librewolf-bin

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-rpath-link,${WRKDIR}/build/dist/bin
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-rpath-link,${PREFIX}/lib

# Workaround for https://bugs.llvm.org/show_bug.cgi?id=46366
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fexperimental-new-pass-manager

SUBST_CLASSES+=			dfly_malloc_h
SUBST_STAGE.dfly_malloc_h=	pre-configure
SUBST_MESSAGE.dfly_malloc_h=	Dont include malloc.h on dragonflybsd
SUBST_SED.dfly_malloc_h=	-e 's,HAVE_MALLOC_H,HAVE_MALLOC_H \&\& !defined(__DragonFly__),g'
SUBST_FILES.dfly_malloc_h+=	media/ffvpx/libavutil/mem.c

SUBST_CLASSES+=			paths
SUBST_STAGE.paths=		pre-configure
SUBST_FILES.paths=		../firefox.sh
SUBST_VARS.paths=		PREFIX MOZILLA

.include "mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=	lib/${MOZILLA}/omni.ja

MOZILLA=	${PKGBASE}

.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=		Firefox
MOZILLA_BRANDING=	official
.else
MOZILLA_NAME=		Browser
MOZILLA_BRANDING=	unofficial
.endif

pre-configure:
# As of 106.0, .in template files are not patched.
#	cd ${WRKSRC} && autoconf
#	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars
#	Do not fetch Rust Cargo file via network during build
.if !defined(FIREFOX_MAINTAINER)
	mv ${WRKDIR}/dist ${WRKSRC}/${OBJDIR}
.endif

.if defined(FIREFOX_MAINTAINER)
# Create files needed only by the firefox maintainer when updating
# the package
# XXX - manually removing the .*_done files is wrong!
.PHONY: build-list
build-list:
	cd ${WRKSRC}/${OBJDIR}/dist/bin/browser/chrome && \
		find . -type f | sort > ${OUT:Q}

NODE_LIST=	"${WRKDIR}/node.list"
NO_NODE_LIST=	"${WRKDIR}/no-node.list"
NODE_FILES=	"${WRKDIR}/node.flist"

.PHONY: maintainer-files
maintainer-files:
	rm -f ${FILESDIR}/node-wrapper.sh
	V=$$( node -v ) && \
	    printf '#! /bin/sh\n\nVERS=%s\n\nif [ "$$1" = "-v" ] || [ "$$1" = "--version" ]; then\n\tprintf "$${VERS}\\n"\nfi\n\nexit 0\n' $$V \
	    > ${FILESDIR}/node-wrapper.sh && \
	    chmod 0755 ${FILESDIR}/node-wrapper.sh
	rm -f ${WRKDIR}/.build_done ${WRKDIR}/.configure_done
	${MAKE} MAINTAINER_INTERNAL=yes build
	${MAKE} MAINTAINER_INTERNAL=yes OUT="${NO_NODE_LIST}" build-list
	${MAKE} OUT="${NODE_LIST}" build-list
	${DIFF} -u "${NO_NODE_LIST}" "${NODE_LIST}" | \
	    ${AWK} \
	    '/^\+\.\//{ printf("dist/bin/browser/chrome/%s\n", gensub(/^\+\.\//, "", "")) }' \
	    > "${NODE_FILES}"
	cd ${WRKSRC}/${OBJDIR} && tar -c -T "${NODE_FILES}" -z \
	    -f ${FILESDIR}/nodejs-output-${PKGVERSION_NOREV}.tgz
.endif

pre-patch:

	for f in $$(find ${WRKSRC}/third_party/libwebrtc -name moz.build -type f) ; \
	do \
		${AWK} -f ${FILESDIR}/replace-moz.build.awk $$f > $$f.new; mv $$f.new $$f ; \
	done
	for f in $$(find ${WRKSRC}/third_party/abseil-cpp -name moz.build -type f) ; \
	do \
		${AWK} -f ${FILESDIR}/replace-moz.build.awk $$f > $$f.new; mv $$f.new $$f ; \
	done

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}|g'				\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications

post-extract:
	${CP} ${FILESDIR}/firefox.sh ${WRKDIR}/firefox.sh

post-install:
.if ${OPSYS} == "NetBSD" && ${X11_TYPE} == "native"
	${INSTALL_SCRIPT} ${WRKDIR}/firefox.sh ${DESTDIR}${PREFIX}/bin/${MOZILLA}
.else
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${ECHO} '${PREFIX}/lib/${MOZILLA}/${MOZILLA} "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA}
.endif
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
.for i in 16 22 24 32 48 64 128 256
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/browser/branding/${MOZILLA_BRANDING}/default${i}.png \
	  ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/${MOZILLA}.png
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
