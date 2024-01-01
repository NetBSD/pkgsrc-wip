# $NetBSD$

DISTNAME=	newsraft-0.22
CATEGORIES=	news
MASTER_SITES=	https://codeberg.org/newsraft/newsraft

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://codeberg.org/newsraft
COMMENT=	Terminal based feed reader
LICENSE=	isc

WRKSRC=	${WRKDIR}/newsraft

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
MAKE_FILE=	makefile

# According to the documentation, these are runtime
# depends as well.
DEPENDS+=	curl>=7.87.0:../../www/curl
DEPENDS+=	expat>=2.4.8:../../textproc/expat
# TODO: this is the Google version we need
# https://codeberg.org/grisha/gumbo-parser without only in wip
DEPENDS+=	gumbo-parser>=0.11.0:../../wip/gumbo-parser
DEPENDS+=	ncursesw>=6.2:../../devel/ncursesw
DEPENDS+=	sqlite3>=3.36.0:../../databases/sqlite3
DEPENDS+=	yajl>=2.1.0:../../devel/yajl
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

INSTALLATION_DIRS+=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newsraft ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_MAN} ${WRKSRC}/doc/newsraft.1 ${DESTDIR}${PREFIX}/man/man1

.include "../../www/curl/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../wip/gumbo-parser/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
