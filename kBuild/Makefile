# $NetBSD: Makefile,v 1.3 2010/06/04 09:08:04 tnn2 Exp $
#

DISTNAME=	kBuild-0.1.5-p2-all
PKGNAME=	kBuild-0.1.5p2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netlabs.org/pub/kbuild/

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	ftp://ftp.netlabs.org/pub/kbuild/
COMMENT=	Framework for writing simple makefiles for complex tasks
LICENSE=	gnu-gpl-v3 # but also various other licenses in 3rd party code

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
WRKSRC=			${WRKDIR}/kBuild-0.1.5-p2

USE_TOOLS+=	pax gmake autoconf automake autoreconf perl flex bison

.include "../../mk/bsd.prefs.mk"

KBUILD_PLATFORM=	${LOWER_OPSYS}.${MACHINE_ARCH:S/x86_64/amd64/:S/i386/x86/}
KBUILD_BIN_PATH=	${WRKSRC}/kBuild/bin/${KBUILD_PLATFORM}
MAKE_ENV+=		WRKSRC=${WRKSRC}

post-extract:
.if ${OPSYS} == "NetBSD"
	cp ${FILESDIR}/strtofflags.c ${WRKSRC}/src/kmk
.endif
	rm -rf ${WRKSRC}/kBuild/bin
	mkdir -p ${KBUILD_BIN_PATH}
	ln -s ${SH} ${KBUILD_BIN_PATH}/kmk_ash

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ${FILESDIR}/bootstrap.sh

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	  `${SH} ${WRKSRC}/kBuild/env.sh --full --eval --set` kmk

INSTALLATION_DIRS=	bin

do-install:
	for f in ${WRKSRC}/out/${KBUILD_PLATFORM}/release/kBuild/bin/${KBUILD_PLATFORM}/*; do	\
	  ${INSTALL_PROGRAM} $${f} ${DESTDIR}${PREFIX}/bin;	\
	done

.include "../../mk/bsd.pkg.mk"
