# $NetBSD: Makefile,v 1.4 2004/02/11 05:59:04 minskim Exp $

DISTNAME=	libpathan-1.2-2-src
PKGNAME=	${DISTNAME:S/-2-src/.2/}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-2-src//}
CATEGORIES=	textproc
MASTER_SITES=	http://software.decisionsoft.com/software/pathan-1.2r2/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://software.decisionsoft.com/
COMMENT=	Library to parse and evaluate XPath expressions

BUILD_DEPENDS=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BISON=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	XERCESCROOT=${LOCALBASE}
CONFIGURE_ARGS+=	YACC=${LOCALBASE}/bin/bison

.include "../../textproc/xerces-c/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
