# $NetBSD$

DISTNAME=	inform-10.1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ganelson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} inweb-7.2.0.tar.gz
SITES.inweb-7.2.0.tar.gz= -https://github.com/ganelson/inweb/archive/refs/tags/v7.2.0.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ganelson/inform/
COMMENT=	Inform 7 programming language
LICENSE=	artistic-2.0

TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

# Package builds with clang specific switches
PKGSRC_COMPILER=	clang

INSTALLATION_DIRS+=	bin libexec libdata

USE_TOOLS+=	bash gmake pax

WRKSRC=		${WRKDIR}

post-extract:
	${MV} ${WRKDIR}/inweb-* ${WRKDIR}/inweb
	${MV} ${WRKDIR}/inform-* ${WRKDIR}/inform
	${LN} -s ${WRKDIR}/inweb ${WRKDIR}/inform/inweb
	${MKDIR} ${WRKDIR}/inweb/Tangled

do-build: inweb inform
.PHONY: inweb inform
inweb:
	cd ${WRKDIR} && ${BASH} inweb/scripts/first.sh unix
inform: inweb
	cd ${WRKDIR}/inform && ${BASH} scripts/first.sh

post-build:
	${ECHO} '#!/bin/sh' > ${WRKSRC}/inform.sh
	${ECHO} ${PREFIX}'/libexec/inform7 -internal '${PREFIX}'/libdata/inform7/Internal "$$@"' >> ${WRKSRC}/inform.sh

do-install:
.for file in inform7
	${INSTALL_PROGRAM} ${WRKSRC}/inform/${file}/Tangled/${file} ${DESTDIR}${PREFIX}/libexec
.endfor
	cd ${WRKDIR}/inform/inform7 && ${PAX} -pp -rw * ${DESTDIR}${PREFIX}/libdata/inform7
	${INSTALL_SCRIPT} ${WRKSRC}/inform.sh ${DESTDIR}${PREFIX}/bin/inform7

.include "../../mk/bsd.pkg.mk"
