# $NetBSD: Makefile,v 1.1.1.1 2007/03/20 16:04:06 jakllsch Exp $
#

DISTNAME=	mcast-tools-20061214
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcast-tools/}

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://mcast-tools.sourceforge.net/
COMMENT=	IPv6 multicast utilites based on KAME Project originals

USE_LANGUAGES+=	c
GNU_CONFIGURE=	yes

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		pim6*d/pim6*d.8
SUBST_SED.fix-paths=            -e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
