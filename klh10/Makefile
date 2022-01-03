# $NetBSD$

DISTNAME=	klh10-2.0
PKGNAME=	klh10-2.0.12.2021.08.19
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=PDP-10/}
GITHUB_PROJECT=	klh10
GITHUB_TAG=	c92bb5f10426f24cdeadd27651c5d068ef7a4230

# Also fetch this file.
DISTFILES+=			${DEFAULT_DISTFILES}	# from github
DISTFILES+=			panda-dist.tar.gz
SITES.panda-dist.tar.gz=	http://panda.trailing-edge.com/
# Store it in subdir klh10-2.0h because the previous package did so.
# TODO but this doesn't work...
DIST_SUBDIR.panda-dist.tar.gz=	klh10-2.0h

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	http://panda.trailing-edge.com/
COMMENT=	PDP-10 KS10/KL10B CPU model emulator
#LICENSE=	# KLH10 Free-Fork License

USE_TOOLS+=	automake autoconf autoheader
USE_TOOLS+=	pax gzip
GNU_CONFIGURE=	yes

CONFIGURE_DIRS=		${WRKSRC}/build
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--enable-bridge
CONFIGURE_ARGS+=	--disable-lights	# req's libusb
CONFIGURE_ARGS+=	--with-vde=no		# no pkg for this

BUILD_DIRS=	build

KLH10_HOME=	${PREFIX}/libexec/klh10
KLH10_SHARE=	${PREFIX}/share/klh10
PANDA=		${KLH10_SHARE}/panda

pre-configure:
	cd ${WRKSRC} && ./autogen.sh
	cd ${WRKSRC} && mkdir ${CONFIGURE_DIRS}

do-install:
.for emu in kl ks ks-its
	cd ${WRKSRC}/build/bld-${emu} && env KLH10_HOME=${DESTDIR}${KLH10_HOME}/home-${emu} make install
	rm -rf ${DESTDIR}${KLH10_HOME}/home-${emu}/flushed
.endfor
	cd ${WRKSRC}/run; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/share/klh10
	cd ${WRKSRC}/doc; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/share/klh10
# TODO: install Panda TOPS-20 disk image and related files
#       but ONLY IF NOT PRESENT ALREADY.
	cd ${WRKDIR}/panda-dist; \
	    ${MKDIR} ${DESTDIR}${PANDA}; \
	    gzip -k RH20.RP07.1; \
	    ${INSTALL_DATA} RH20.RP07.1.gz ${DESTDIR}${PANDA}/; \
	    ${INSTALL_DATA} CPYRIGHT PandaPanel.jpg README* ${DESTDIR}${PANDA}/; \
	    ${INSTALL_SCRIPT} inst-klt20* klt20* ${DESTDIR}${PANDA}/
	cd ${DESTDIR}${PANDA}; \
	    for f in boot.sav mtboot.sav; \
	    do \
	        ln -s ${KLH10_SHARE}/klt20/$$f .; \
	    done; \
	    for f in dpni20 dprpxx dptm03 enaddr kn10-kl tapedd udlconv \
	             uexbconv vdkfmt wfconv wxtest; \
	    do \
	        ln -s ${KLH10_HOME}/home-kl/$$f .; \
	    done

.include "../../mk/bsd.pkg.mk"
