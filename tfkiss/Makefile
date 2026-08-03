# $NetBSD$

DISTNAME=	tfkiss-1.3.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:S,^,-,:=kq6up/tfkiss/releases/download/1.3.2/tfkiss-1.3.2.tar.gz}

MAINTAINER=	christopher.maness@gmail.com
HOMEPAGE=	https://github.com/kq6up/tfkiss
COMMENT=	Software implementation of TheFirmware for use with TNT
# TheFirmware is Copyright NORD><LINK e.V. and is distributed under
# ALAS, the general licence for amateur radio software, which permits
# non-commercial use, modification and redistribution.  The accompanying
# copyright notice additionally asks that modified versions be
# distributed only with the consent of NORD><LINK, which can no longer
# be obtained: the association appears to be dissolved and the author of
# the Unix port is deceased.  See LICENSE-NOTES in the distribution for
# a full account.  Pick generic-nonlicense so potential users can
# evaluate for themselves.
LICENSE=	generic-nonlicense

RESTRICTED=		No clear license, no commercial use
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

# XPID, FLEXNET and AXIP are enabled by default upstream as of 1.3.0,
# so no CONFIGURE_ARGS are needed to obtain a full featured build.

.include "../../mk/bsd.pkg.mk"
