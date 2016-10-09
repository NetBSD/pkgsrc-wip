# $NetBSD$

DISTNAME=	verilator-3.886
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.org/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.veripool.org/wiki/verilator/Intro
COMMENT=	Free and fast Verilog HDL simulator
LICENSE=	gnu-lgpl-v3 OR artistic

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config bison gmake perl autoconf flex
USE_LANGUAGES=	c c++

DEPENDS+=	p5-Getopt-Long>=[0-9]*:../../devel/p5-Getopt-Long

REPLACE_PERL+=	test_regress/*.pl
REPLACE_PERL+=	test_regress/t/*.pl
REPLACE_PERL+=	test_regress/t/t_pipe_filter.pf
REPLACE_PERL+=	test_regress/t/t_pipe_exit_bad.pf
REPLACE_PERL+=	test_regress/t/t_case_deep.v
REPLACE_PERL+=	src/vlcovgen
REPLACE_PERL+=	src/bisonpre
REPLACE_PERL+=	src/config_rev.pl
REPLACE_PERL+=	src/cppcheck_filtered
REPLACE_PERL+=	src/astgen
REPLACE_PERL+=	src/pod2latexfix
REPLACE_PERL+=	src/flexfix
REPLACE_PERL+=	test_verilated/*.pl

PKGCONFIG_OVERRIDE+=	verilator.pc.in

TEST_TARGET=	test

pre-configure:
	${RUN} cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
