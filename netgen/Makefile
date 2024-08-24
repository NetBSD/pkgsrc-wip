# $NetBSD$

DISTNAME=	1.5.277
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=RTimothyEdwards/}
GITHUB_PROJECT=	netgen
GITHUB_TAG=	refs/tags/1.5.277
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RTimothyEdwards/netgen/
COMMENT=	Complete LVS tool for comparing SPICE or verilog netlists
LICENSE=	gnu-gpl-v1

WRKSRC=		${WRKDIR}/netgen-1.5.277
GNU_CONFIGURE=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
