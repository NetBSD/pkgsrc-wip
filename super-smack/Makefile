# $NetBSD: Makefile,v 1.5 2009/03/22 10:43:35 bartoszkuzma Exp $
#

DISTNAME=		super-smack-1.3
CATEGORIES=		benchmarks
MASTER_SITES=		http://vegan.net/tony/supersmack/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://vegan.net/tony/supersmack/
COMMENT=		Database benchmarking tool

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-datadir=/tmp
CONFIGURE_ARGS+=	--with-smacks-dir=${PREFIX}/share/smacks

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/super-smack
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/super-smack
	${INSTALL_DATA} ${WRKSRC}/MANUAL ${PREFIX}/share/doc/super-smack
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/super-smack
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${PREFIX}/share/doc/super-smack

.include "../../mk/bsd.pkg.mk"
