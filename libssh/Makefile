# $NetBSD: Makefile,v 1.3 2005/04/11 21:13:50 tvierling Exp $
#

DISTNAME=	libssh-0.1
CATEGORIES=	security
MASTER_SITES=	http://www.0xbadc0de.be/libssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://0xbadc0de.be/
COMMENT=	Working SSH implementation by the mean of a library

GNU_CONFIGURE=	YES

post-install:

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/API.txt ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libssh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
