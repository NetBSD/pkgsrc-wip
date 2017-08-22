# $NetBSD$

DISTNAME=	ATS2-Postiats-0.3.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ats2-lang/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ats-lang.org/
COMMENT=	Programming language unifying implementation with formal specification
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake

MAKE_JOBS_SAFE=	no
MAKE_FLAGS+=	LDFLAGS+=

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
