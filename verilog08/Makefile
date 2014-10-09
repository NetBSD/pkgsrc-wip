# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:32 thomasklausner Exp $
#

DISTNAME=	verilog-0.8.7
PKGNAME=	${DISTNAME:C/verilog/verilog08/}
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html
COMMENT=	Verilog simulation and synthesis tool (old version of 0.8)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison lex
CONFIGURE_ARGS+=	--without-ipal
TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
