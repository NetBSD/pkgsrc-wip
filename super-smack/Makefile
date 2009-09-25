# $NetBSD: Makefile,v 1.6 2009/09/25 09:04:55 bartoszkuzma Exp $
#

DISTNAME=		super-smack-1.3
CATEGORIES=		benchmarks
MASTER_SITES=		http://vegan.net/tony/supersmack/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://vegan.net/tony/supersmack/
COMMENT=		Database benchmarking tool
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=    user-destdir

CONFIGURE_ARGS+=	--with-datadir=/tmp
CONFIGURE_ARGS+=	--with-smacks-dir=${DESTDIR}${PREFIX}/share/smacks

DOCDIR=			${PREFIX}/share/doc/super-smack

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES \
		${WRKSRC}/MANUAL \
		${WRKSRC}/README \
		${WRKSRC}/TUTORIAL \
		${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
