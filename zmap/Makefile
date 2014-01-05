# $NetBSD: Makefile,v 1.1 2014/01/05 11:25:31 thomasklausner Exp $

DISTNAME=	v1.1.1
PKGNAME=	${DISTNAME:S/v/zmap-/}
CATEGORIES=	net
MASTER_SITES=	https://github.com/zmap/zmap/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zmap.io/
COMMENT=	Network scanner that scales to Internet-wide network studies
LICENSE=	apache-2.0

BUILD_DEPENDS+=	gengetopt-[0-9]*:../../devel/gengetopt

DIST_SUBDIR=	zmap

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=	yes
USE_TOOLS+=	yacc

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
