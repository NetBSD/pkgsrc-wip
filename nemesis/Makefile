# $NetBSD: Makefile,v 1.1.1.1 2003/07/09 15:00:52 adrian_p Exp $

DISTNAME=	nemesis-1.32
CATEGORIES=	security net
MASTER_SITES=	http://www.packetfactory.net/projects/nemesis/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.packetfactory.net/projects/nemesis/
COMMENT=	Nemesis is a command-line UNIX network packet injection suite

USE_BUILDLINK2=	yes
GNU_CONFIGURE=  yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nemesis
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/doc/nemesis
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nemesis
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/nemesis

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
