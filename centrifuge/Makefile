# $NetBSD$
#
###########################################################
#                  Generated by fbsd2pkg                  #
#              Mon Oct 29 07:50:44 CDT 2018               #
###########################################################

DISTNAME=	centrifuge-${PV}-beta
PKGNAME=	centrifuge-${PV}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=infphilo/}
GITHUB_PROJECT=	centrifuge
GITHUB_TAG=	v${PV}-beta

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.ccb.jhu.edu/software/centrifuge/
COMMENT=	Novel microbial classification engine
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake
REPLACE_PERL=	centrifuge centrifuge-kreport *.pl
REPLACE_PYTHON=	centrifuge-build centrifuge-inspect centrifuge-download

# FIXME: Fix asm blocks
MAKE_ENV+=	POPCNT_CAPABILITY=0 DOCSDIR=${DOCSDIR}

PV=		1.0.4
DOCSDIR=	${PREFIX}/share/doc/centrifuge

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
