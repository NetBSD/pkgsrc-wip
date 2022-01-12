# $NetBSD: Makefile,v 1.1 2022/01/11 20:10:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-${SNAPSTAMP}
COMMENT=	mrustc meta package (builds several other "mrust-" packages)
DISTFILES=	

SUBST_STAGE.atomic-pathfix=	none

DEPENDS+=	mrust-mrustc>=${SNAPSTAMP}:../../wip/mrust-mrustc
DEPENDS+=	mrust-minicargo>=${SNAPSTAMP}:../../wip/mrust-minicargo
DEPENDS+=	mrust-libs>=${SNAPSTAMP}:../../wip/mrust-libs
DEPENDS+=	mrust-rustc>=${SNAPSTAMP}:../../wip/mrust-rustc
DEPENDS+=	mrust-cargo>=${SNAPSTAMP}:../../wip/mrust-cargo

do-build:

do-install:

.include "../../mk/bsd.pkg.mk"
