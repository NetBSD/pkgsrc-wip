# $NetBSD$

DISTNAME=	ATS2-Postiats-0.3.12
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

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Fixing version.
SUBST_FILES.version=	configure
SUBST_SED.version=	-e "s/0\.3\.11/0.3.12/g"

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
