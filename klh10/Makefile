# $NetBSD$

DISTNAME=	klh10-2.0
PKGNAME=	klh10-2.0.12.2021.08.19
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=PDP-10/}
GITHUB_PROJECT=	klh10
GITHUB_TAG=	c92bb5f10426f24cdeadd27651c5d068ef7a4230

# TODO: also fetch this file
#DISTFILES+=	panda-dist.tar.gz
#MASTER_SITE.panda-dist.tar.gz=	http://panda.trailing-edge.com/

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	http://panda.trailing-edge.com/
COMMENT=	PDP-10 KS10/KL10B CPU model emulator
#LICENSE=	# KLH10 Free-Fork License

USE_TOOLS+=	automake autoconf autoheader
USE_TOOLS+=	pax
GNU_CONFIGURE=	yes

CONFIGURE_DIRS=		${WRKSRC}/build
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--enable-bridge
CONFIGURE_ARGS+=	--disable-lights	# req's libusb
CONFIGURE_ARGS+=	--with-vde=no		# no pkg for this

BUILD_DIRS=	build

KLH10_HOME=	${DESTDIR}${PREFIX}/libexec/klh10

pre-configure:
	cd ${WRKSRC} && ./autogen.sh
	mkdir ${CONFIGURE_DIRS}

do-install:
.for emu in kl ks ks-its
	cd ${WRKSRC}/build/bld-${emu} && env KLH10_HOME=${KLH10_HOME}/home-${emu} make install
	rmdir ${KLH10_HOME}/home-${emu}/flushed
.endfor
	cd ${WRKSRC}/run; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/share/klh10
	cd ${WRKSRC}/doc; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/share/klh10
# TODO: also install Panda TOPS-20 disk image and related files
#       if not present already

.include "../../mk/bsd.pkg.mk"
