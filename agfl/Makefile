# $NetBSD: Makefile,v 1.1 2014/12/17 22:02:10 rhialto Exp $

DISTNAME=	agfl-${AGFL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.ru.nl/pub/agfl/${AGFL_VERSION}/src/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} # ${DOC_FILE}

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	http://www.cs.ru.nl/agfl/
COMMENT=	Formalism for the syntactic description of Natural Languages

DIST_SUBDIR=	agfl-${AGFL_VERSION}

AGFL_VERSION=		3.2
CONFIGURE_ARGS +=	--with-cdl3=${BUILDLINK_PREFIX.cdl3}
MAKE_JOBS_SAFE=		NO
LICENSE=		gnu-gpl-v3

INSTALLATION_DIRS+=	share/doc/agfl
INSTALLATION_DIRS+=	share/agfl

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		perl

BUILD_DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
BUILD_DEPENDS+=	tex-boxedminipage-[0-9]*:../../print/tex-boxedminipage

.include "../../lang/cdl3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
