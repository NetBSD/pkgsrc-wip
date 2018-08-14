# $NetBSD: Makefile,v 1.3 2015/01/20 12:02:10 ahp-nils Exp $

DISTNAME=	zmap-1.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=zmap/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zmap.io/
COMMENT=	Network scanner that scales to Internet-wide network studies
LICENSE=	apache-2.0

BUILD_DEPENDS+=	gengetopt-[0-9]*:../../devel/gengetopt

USE_CMAKE=	yes
USE_TOOLS+=	yacc

.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
