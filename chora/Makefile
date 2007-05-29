# $NetBSD: Makefile,v 1.6 2007/05/29 02:02:57 schmonz Exp $
#

DISTNAME=	chora-1.2.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.horde.org/pub/chora/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.horde.org/chora/
COMMENT=	Another CVS-via-web system

#DEPENDS+=	cvs>=1.11.20:../../devel/scmcvs
DEPENDS+=	horde>=2.2.4:../../www/horde

USE_LANGUAGES=	# empty
NO_BUILD=	YES

CHORADIR=	${PREFIX}/share/chora
EGDIR=		${PREFIX}/share/examples/chora

do-install:
	${INSTALL_DATA_DIR} ${CHORADIR}
	${CP} -R ${WRKSRC}/* ${CHORADIR}

.include "../../mk/bsd.pkg.mk"
