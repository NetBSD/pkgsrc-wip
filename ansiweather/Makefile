# $NetBSD: Makefile,v 1.2 2015/05/16 21:10:05 krytarowski Exp $

GITHUB_PROJECT=	ansiweather
DISTNAME=	1.02
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=fcambus/ansiweather/}
COMMENT=	Display current weather conditions in your terminal
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/ansiweather-1.02
USE_LANGUAGES=	# none

USE_TOOLS+=	awk:run bash:run date:run grep:run

DEPENDS+=	bc-[0-9]*:../../math/bc
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	jq-[0-9]*:../../devel/jq

REPLACE_BASH+=	ansiweather

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALL_UNSTRIPPED=	yes

DOCDIR=		share/doc/ansiweather
EGDIR=		share/examples/ansiweather

CONF_FILES+=	${EGDIR}/ansiweatherrc.example ${PKG_SYSCONFDIR}/ansiweatherrc

SUBST_CLASSES+=		config shebang
SUBST_FILES.config=	ansiweather
SUBST_SED.config=	-e 's,~/.ansiweatherrc,${PKG_SYSCONFDIR}/ansiweatherrc,'
SUBST_STAGE.config=	post-patch

SUBST_FILES.shebang=	ansiweather
SUBST_SED.shebang=	-e 's,/usr/bin/env bash,${BASH},'
SUBST_STAGE.shebang=	post-patch

AUTO_MKDIRS=	yes

do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/ansiweather ${DESTDIR}${PREFIX}/bin
.for f in AUTHORS ChangeLog README.md ansiweather.plugin.zsh
	${RUN}${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${RUN}${INSTALL_DATA} ${WRKSRC}/ansiweatherrc.example \
	                      ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
