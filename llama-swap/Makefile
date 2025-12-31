# $NetBSD$

GITHUB_TAG=	v180
DISTNAME=	llama-swap-${GITHUB_TAG:S,^v,,}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=mostlygeek/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mostlygeek/llama-swap/
COMMENT=	Reliable model swapping for any local OpenAI compatible server
LICENSE=	mit

USE_TOOLS+=	gmake
TOOL_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

USE_LANGUAGES=	c

.include "go-modules.mk"

# XXX
pre-build:
	mkdir ${WRKSRC}/tmp && \
	cd ${WRKSRC}/tmp && \
	npm install pnpm && \
	cd ${WRKSRC}/ui	&& \
	${WRKSRC}/tmp/node_modules/.bin/pnpm i && \
	cd ${WRKSRC} \
	&& ${GMAKE} ui

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
