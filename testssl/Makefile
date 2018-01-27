# $NetBSD$

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	testssl-2.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=drwetter/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://testssl.sh/
COMMENT=	Checks servers for TLS/SSL flaws
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	testssl.sh
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	bash-[0-9]*:../../shells/bash

NO_BUILD=		yes
INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

REPLACE_INTERPRETER+=	envbash
REPLACE.envbash.old=	'/usr/bin/env\ bash'
REPLACE.envbash.new=	${PREFIX}/bin/bash
REPLACE_FILES.envbash=	testssl.sh

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/testssl.sh ${DESTDIR}${PREFIX}/bin/testssl
	${INSTALL} -m 0644 ${WRKSRC}/Readme.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README.md

.include "../../mk/bsd.pkg.mk"
