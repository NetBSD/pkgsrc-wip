# $NetBSD: Makefile,v 1.0 2023/12/27 13:30:00 dkazankov Exp $

.include "version.mk"
PKGNAME=alire-${ALIRE_VERSION}

CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alire-project/alire
COMMENT=	Ada LIbrary REpository
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	ada

.include "../../mk/bsd.prefs.mk"

DISTNAME=	${PKGNAME}-rc1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
GITHUB_TAG=	v${ALIRE_VERSION}-rc1
MASTER_SITES=	${MASTER_SITE_GITHUB:=alire-project/}

USE_TOOLS+=	git

#NO_CONFIGURE=	yes

GCC_REQD+=	13
.include "../../wip/gcc13-gnat/gcc.mk"

.include "../../wip/gprbuild/buildlink3.mk"

CGPRDIR=	${WRKDIR}/.home

SUBST_CLASSES+=		buildlink
SUBST_STAGE.buildlink=	post-configure
SUBST_FILES.buildlink=	../.home/buildlink.cgpr
SUBST_MESSAGE.buildlink=Set work directory path in config project
SUBST_SED.buildlink=	-e 's,@WRKDIR@,${WRKDIR},g'

MAKE_ENV+=		ALIRE_OS=netbsd
MAKE_PROGRAM=		gprbuild
MAKE_FILE=		alr_env
MAKE_FLAGS=		-j0 -p -P
BUILD_MAKE_FLAGS=	--config=${CGPRDIR}/buildlink.cgpr

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin \( -type f -or -type l \) -print | ${SORT};

post-extract:
	${RUN} \
	cd ${WRKSRC} \
	&& git init \
	&& git config submodule.recurse true \
	&& git remote add origin ${MASTER_SITE_GITHUB:=alire-project/}alire.git \
	&& git fetch origin tag ${GITHUB_TAG} --no-tags \
	&& git checkout tags/${GITHUB_TAG} -f \
	&& git submodule init \
	&& git submodule update

pre-configure:
	${RUN} ${CP} ${PKGDIR}/files/buildlink.cgpr ${CGPRDIR}/

do-build:
	${RUN} \
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${MAKE_FILE} ${BUILD_MAKE_FLAGS}

do-install:
	${RUN} \
	cd ${WRKSRC} \
	&& mkdir -p ${DESTDIR}${PREFIX}/bin \
	&& install -m0755 bin/alr ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
