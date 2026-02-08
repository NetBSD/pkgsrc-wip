# $NetBSD$

DISTNAME=	convos-8.07
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=convos-chat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/convos-chat/convos/
COMMENT=	Multiuser chat application
LICENSE=	artistic-2.0

USE_TOOLS+=	pax
USE_TOOLS+=	perl perl:run

DEPENDS+=	p5-IRC-Utils-[0-9]*:../../chat/p5-IRC-Utils
#DEPENDS+=	p5-Unicode-UTF8-[0-9]*:../../converters/p5-Unicode-UTF8
DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
#DEPENDS+=	p5-Future-[0-9]*:../../devel/p5-Future
DEPENDS+=	p5-Module-Install-[0-9]*:../../devel/p5-Module-Install
DEPENDS+=	p5-Syntax-Keyword-Try-[0-9]*:../../devel/p5-Syntax-Keyword-Try
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-File-ReadBackwards-[0-9]*:../../textproc/p5-File-ReadBackwards
#DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious

WRKSRC=		${WRKDIR}/${DISTNAME}

SUBST_CLASSES+=		moreperl
SUBST_STAGE.moreperl=	post-extract
SUBST_MESSAGE.moreperl=	Fixing perl paths
SUBST_FILES.moreperl=	script/convos
SUBST_SED.moreperl=	-e 1s,/usr/bin/env.perl,${PERL5:Q},

WEBUI_DIR=		${PREFIX}/share/convos

#XXX to generate the frontend from source
#TOOL_DEPENDS+=	nodejs>=22:../../lang/nodejs22
#.PHONY: generate-frontend
#generate-frontend:
#	cd ${WRKSRC} && \
#		npm install && \
#		npm run build

do-configure:
	cd ${WRKSRC} && ${PERL5} Makefile.PL

post-install:
	cd ${WRKSRC} && ${PAX} -rw public ${DESTDIR}${WEBUI_DIR}

.include "../../mk/bsd.pkg.mk"
