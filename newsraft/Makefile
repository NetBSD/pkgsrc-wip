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

# According to the documentation, curl and yajl are runtime
# depends as well.
DEPENDS+=	curl>=7.87.0:../../www/curl
DEPENDS+=	expat>=2.4.8:../../textproc/expat
# TODO: this is the Google version we need
# https://codeberg.org/grisha/gumbo-parser
#DEPENDS+=	gumbo-parser>=0.11.0:../../www/gumbo-parser
DEPENDS+=	ncursesw>=6.2:../../devel/ncursesw
DEPENDS+=	sqlite3>=3.36.0:../../databases/sqlite3
DEPENDS+=	yajl>=2.1.0:../../devel/yajl
TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc


.include "../../www/curl/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
