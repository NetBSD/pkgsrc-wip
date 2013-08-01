# $NetBSD: Makefile,v 1.6 2013/08/01 01:51:25 othyro Exp $
#

DISTNAME=	kytea-0.4.6
CATEGORIES=	textproc
MASTER_SITES=	http://www.phontron.com/kytea/download/

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.phontron.com/kytea/
COMMENT=	Kyoto Text Analysis Toolkit
LICENSE=	apache-2.0

RESTRICTED=	Included model is not re-distributed without prior permission.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKGCONFIG_OVERRIDE+=	kytea.pc.in

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

do-test:
	${RUN}cd ${WRKSRC}/src/test; ${SETENV} ${TEST_ENV} ./test-kytea

.include "../../mk/bsd.pkg.mk"
