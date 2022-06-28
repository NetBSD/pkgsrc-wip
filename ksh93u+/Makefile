# $NetBSD$

DISTNAME=	v1.0.0-beta.2
PKGVER=		1.0.0
PKGNAME=	${GITHUB_PROJECT}93u+-${PKGVER}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=ksh93/}
GITHUB_PROJECT=	ksh
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://github.com/ksh93/ksh/
COMMENT=	Actively developed fork of AT&T KornShell 93u+
LICENSE=	epl-v1.0

CONFLICTS+=		ast-ksh-[0-9]* static-ast-ksh-[0-9]*

USE_LANGUAGES=		c
FORTIFY_SUPPORTED=	no

MAKEFLAGS+=		CC=${CC:Q} CCFLAGS=${CFLAGS:M*:Q}

CFLAGS.SunOS+=	-std=c11 -D__EXTENSIONS__

PKG_SHELL=		bin/ksh93

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/ksh-${DISTNAME:S,^v,,}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} 				\
		${SH} ./bin/package make ${MAKEFLAGS}

do-install:
	set -e;								\
	arch=`${WRKSRC}/bin/package host`;                              \
	${INSTALL_PROGRAM} ${WRKSRC}/arch/"$${arch}"/bin/ksh 		\
		${DESTDIR}${PREFIX}/bin/ksh93

	${INSTALL_MAN} ${WRKSRC}/src/cmd/ksh93/sh.1 			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ksh93.1

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}				\
		${SH} ./bin/package test

.include "../../mk/bsd.pkg.mk"
