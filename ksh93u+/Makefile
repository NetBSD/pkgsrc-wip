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

USE_LANGUAGES=		c c++
FORTIFY_SUPPORTED=	no
MAKEFLAGS+=		CC=${CC:Q} CCFLAGS=${CFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKEFLAGS+=	CCFLAGS="-D_NETBSD_SOURCE ${CFLAGS}"
.endif

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	CCFLAGS="-std=c11 -D_XPG6 ${CFLAGS}"
.endif

PKG_SHELL=		bin/ksh93

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=	${WRKDIR}/ksh-${DISTNAME:S,^v,,}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${TOOLS_SHELL} ${WRKSRC}/bin/package \
		make ${MAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arch/*/bin/ksh \
		${DESTDIR}${PREFIX}/bin/ksh93
	${INSTALL_MAN} ${WRKSRC}/src/cmd/ksh93/sh.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ksh93.1

.include "../../mk/bsd.pkg.mk"
