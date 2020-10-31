# $NetBSD: Makefile,v 1.20 2020/08/31 18:09:52 wiz Exp $

DISTNAME=	rakudo-star-2020.10
CATEGORIES=	lang perl6
MASTER_SITES=	http://rakudo.org/downloads/star/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rakudo.org/
COMMENT=	Perl 6 reference implementation
LICENSE=	artistic-2.0

#AKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

PLIST_SRC+=	${PLIST_SRC_DFLT}

.if (${OPSYS} != "Darwin")
PLIST_SRC+=	PLIST.shared
.else
USE_TOOLS+=	gmake
.endif

# to find libmoar.so
PKGSRC_MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/lib

PLIST_SUBST+=		PARROT_VERSION=${PARROT_VERSION:Q}
PRINT_PLIST_AWK+=	{ gsub(/${PARROT_VERSION}/, "$${PARROT_VERSION}") }

do-configure:
	(cd ${WRKSRC};  ./bin/rstar install)

do-build:
	(cd ${WRKSRC};  ${MAKE})

do-install:
	(cd ${WRKSRC};  ${GMAKE} install)


.include "../../devel/MoarVM/buildlink3.mk"
.include "../../lang/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
