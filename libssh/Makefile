# $NetBSD: Makefile,v 1.1.1.1 2004/05/13 18:15:45 adrian_p Exp $
#

DISTNAME=	libssh-0.1
CATEGORIES=	security
MASTER_SITES=	http://www.0xbadc0de.be/projects/libssh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://0xbadc0de.be/projects/sshlib.html/
COMMENT=	Working SSH implementation by the mean of a library

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

post-install:

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/API.txt ${PREFIX}/share/doc/libssh
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libssh

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
