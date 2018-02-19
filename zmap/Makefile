# $NetBSD: Makefile,v 1.3 2015/01/20 12:02:10 ahp-nils Exp $

DISTNAME=	v1.2.1
PKGNAME=	${DISTNAME:S/v/zmap-/}
CATEGORIES=	net
MASTER_SITES=	https://github.com/zmap/zmap/archive/
DIST_SUBDIR=	zmap

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zmap.io/
COMMENT=	Network scanner that scales to Internet-wide network studies
LICENSE=	apache-2.0

BUILD_DEPENDS+=	gengetopt-[0-9]*:../../devel/gengetopt

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	yacc

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
