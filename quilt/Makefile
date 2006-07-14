# $NetBSD: Makefile,v 1.1.1.1 2006/07/14 09:32:47 thomasklausner Exp $
#

DISTNAME=		quilt-0.45
CATEGORIES=		devel
MASTER_SITES=		http://download.savannah.gnu.org/releases/quilt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://savannah.nongnu.org/projects/quilt/
COMMENT=		Patch management tool

DEPENDS+=		patch-[0-9]*:../../devel/patch
DEPENDS+=		getopt-[0-9]*:../../misc/getopt
DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils
DEPENDS+=		gsed-[0-9]*:../../textproc/gsed

CONFIGURE_ARGS+=	--with-cp=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}cp
CONFIGURE_ARGS+=	--with-getopt=${PREFIX}/bin/getopt
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+=	--with-sed=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}sed
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
