# $NetBSD: Makefile,v 1.1 2022/01/11 20:10:00 dlb Exp $

SKIP_MRUSTC_SRC=	true
.include "../../wip/mrust/Makefile.common"

##PKGNAME=	mrust-${SNAPSTAMP}
COMMENT=	Meta package for mrustc (builds other "mrust-" packages)
DISTFILES=

.if defined(MR_OUTDIR)
.  undef MR_OUTDIR
.endif

DEPENDS+=	mrust-mrustc>=${SNAPSTAMP}:../../wip/mrust-mrustc
DEPENDS+=	mrust-minicargo>=${SNAPSTAMP}:../../wip/mrust-minicargo
DEPENDS+=	mrust-libs>=${SNAPSTAMP}:../../wip/mrust-libs
DEPENDS+=	mrust-rustc>=${SNAPSTAMP}:../../wip/mrust-rustc
DEPENDS+=	mrust-cargo>=${SNAPSTAMP}:../../wip/mrust-cargo

do-build:

do-install:

.include "../../mk/bsd.pkg.mk"
