# $NetBSD: Makefile,v 1.17 2018/08/22 09:42:59 wiz Exp $
#

DISTNAME=		gromacs-2019
CATEGORIES=		science
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		bacon@NetBSD.org
HOMEPAGE=		http://www.gromacs.org/
COMMENT=		Molecular dynamics package
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake pkg-config
USE_CMAKE=		yes

.include "options.mk"

USE_TOOLS+=		perl:run
REPLACE_PERL=		scripts/demux.pl scripts/xplor2gmx.pl

CHECK_INTERPRETER_SKIP+=	share/gromacs/tutor/gmxdemo/demo

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-msse -msse2
.endif

.include "../../math/fftw/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"	# optional
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"	# optional
.include "../../mk/bsd.pkg.mk"
