# $NetBSD: Makefile,v 1.8 2004/12/02 16:39:00 thomasklausner Exp $
#

DISTNAME=	hydra-4.3-src
PKGNAME=	hydra-4.3
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.thc.org/releases/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.thc.org/
COMMENT=	Login password cracker

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
BUILD_TARGET=	all ssl

CONFIGURE_ARGS+=	--prefix=${PREFIX}

pre-configure:
	${CP} ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.am.new
	${SED} -e 's#@SSLBASE@#${BUILDLINK_PREFIX.openssl}#g' \
		-e 's#@PREFIX@#${PREFIX}#g' \
		< ${WRKSRC}/Makefile.am.new > ${WRKSRC}/Makefile.am

	${CP} ${WRKSRC}/configure ${WRKSRC}/configure.new
	${SED} -e 's#@PREFIX@#${PREFIX}#g' \
		< ${WRKSRC}/configure.new > ${WRKSRC}/configure

.include "../../security/openssl/buildlink3.mk"
.include "../../wip/libssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
