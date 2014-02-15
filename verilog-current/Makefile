# $NetBSD: Makefile,v 1.4 2014/02/15 13:40:19 makoto Exp $

DISTNAME=	verilog-${SNAPDATE}
PKGNAME=	verilog-current-${SNAPDATE}
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://iverilog.icarus.com/
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
INSTALLATION_DIRS+=	include/iverilog
INSTALLATION_DIRS+=	lib/ivl
INSTALLATION_DIRS+=	lib/ivl/include
INSTALLATION_DIRS+=	share/ivl

TEST_DIRS=		.
TEST_TARGET=		check

SUBST_CLASSES+=		dep
SUBST_STAGE.dep=	pre-configure
SUBST_MESSAGE.dep=	Resolve dependency for dep directory (mkdir dep before compile)
SUBST_FILES.dep=	tgt-null/Makefile.in \
			tgt-vlog95/Makefile.in \
			tgt-vvp/Makefile.in \
			tgt-blif/Makefile.in \
			tgt-fpga/Makefile.in \
			tgt-null/Makefile.in \
			tgt-pal/Makefile.in \
			tgt-pcb/Makefile.in \
			tgt-stub/Makefile.in \
			tgt-verilog/Makefile.in \
			tgt-vhdl/Makefile.in \
			tgt-vlog95/Makefile.in \
			tgt-vvp/Makefile.in \
			cadpli/Makefile.in
SUBST_SED.dep=		'-e s,%o: %c,%o: %c dep,'

# probably more simple fix with small patches, but interim solution:
post-install:
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		QUICK_START.txt \
		README.txt      \
	${DESTDIR}${PREFIX}/share/ivl )
# include/iverilog
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		acc_user.h ivl_target.h sv_vpi_user.h veriuser.h vpi_user.h \
	${DESTDIR}${PREFIX}/include/iverilog )
# lib/ivl
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		tgt-blif/blif-s.conf \
		tgt-blif/blif.conf \
		tgt-null/null-s.conf \
		tgt-null/null.conf \
		tgt-pcb/pcb-s.conf \
		tgt-pcb/pcb.conf \
		tgt-stub/stub-s.conf \
		tgt-stub/stub.conf \
		tgt-vhdl/vhdl-s.conf \
		tgt-vhdl/vhdl.conf \
		tgt-vlog95/vlog95-s.conf \
		tgt-vlog95/vlog95.conf \
		vpi/system.sft \
		vpi/v2005_math.sft \
		vpi/v2009.sft \
		vpi/va_math.sft \
		vpi/vhdl_sys.sft \
	${DESTDIR}${PREFIX}/lib/ivl )
# lib/ivl/include
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		constants.vams \
		disciplines.vams \
	${DESTDIR}${PREFIX}/lib/ivl/include )

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
