# $NetBSD$

DISTNAME=	inform-10.1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ganelson/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} inweb-7.2.0.tar.gz
# TODO: fix for inweb download

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ganelson/inform/
COMMENT=	Inform 7 programming language
LICENSE=	artistic-2.0

TOOL_DEPENDS+=	clang-[0-9]*:../../lang/clang

# Package builds with clang specific switches
PKGSRC_COMPILER=	clang

INSTALLATION_DIRS+=	bin

USE_TOOLS+=	bash gmake

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

do-install:
.for file in inform7
	${INSTALL_PROGRAM} ${WRKSRC}/inform/${file}/Tangled/${file} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
