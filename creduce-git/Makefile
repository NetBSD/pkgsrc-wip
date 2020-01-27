# $NetBSD: Makefile,v 1.2 2015/03/04 18:38:19 tnn2 Exp $

DISTNAME=	creduce-2.2.1
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/creduce/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://embed.cs.utah.edu/creduce/
COMMENT=	Reduce compiler-breaking C program to minimal one
LICENSE=	modified-bsd

DEPENDS+=	astyle-[0-9]*:../../devel/astyle
DEPENDS+=	delta-[0-9]*:../../devel/delta
DEPENDS+=	gindent-[0-9]*:../../devel/gindent
DEPENDS+=	p5-Benchmark-Timer-[0-9]*:../../benchmarks/p5-Benchmark-Timer
DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Getopt-Tabular-[0-9]*:../../devel/p5-Getopt-Tabular
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Sys-CPU-[0-9]*:../../sysutils/p5-Sys-CPU

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	flex gmake perl:run

GIT_REPOSITORIES=	creduce
GIT_REPO.creduce=	git://github.com/csmith-project/creduce.git
WRKSRC=			${WRKDIR}/creduce

pre-configure:
	${LN} -s ${LLVM_CONFIG_PATH} ${TOOLS_DIR}/bin/llvm-config

.include "../../lang/libLLVM/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
