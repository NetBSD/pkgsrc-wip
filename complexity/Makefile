# $NetBSD$

DISTNAME=	complexity-1.10
CATEGORIES=	nih
MASTER_SITES=	${MASTER_SITE_GNU:=complexity/}
EXTRACT_SUFX=	.tar.xz
LICENSE=	gnu-gpl-v3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/complexity/
COMMENT=	Tool designed for analyzing the complexity of C program functions
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../devel/autogen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
