# $NetBSD: Makefile,v 1.1 2013/12/20 02:19:53 makoto Exp $

DISTNAME=	verilog-${SNAPDATE}
PKGNAME=	verilog-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (development snapshot version)
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	verilog-[0-9]*
SNAPDATE=		20130827

GCC_REQD+=	3.0
USE_LANGUAGES=	c c++
USE_TOOLS+=		bison gmake lex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ipal
INSTALLATION_DIRS+=	share/ivl

TEST_DIRS=		.
TEST_TARGET=		check

post-install:
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		QUICK_START.txt \
		README.txt      \
	${DESTDIR}${PREFIX}/share/ivl )

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
