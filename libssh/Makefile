# $NetBSD: Makefile,v 1.2 2005/02/07 09:36:04 adrian_p Exp $
#

DISTNAME=	libssh-0.1
CATEGORIES=	security
MASTER_SITES=	http://www.0xbadc0de.be/libssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://0xbadc0de.be/
COMMENT=	Working SSH implementation by the mean of a library

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

post-install:

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/API.txt ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libssh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
