# $NetBSD: Makefile,v 1.1 2010/01/30 20:47:40 bartoszkuzma Exp $
#

DISTNAME=	uni2ascii-4.14
CATEGORIES=	textproc
MASTER_SITES=	http://billposer.org/Software/Downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://billposer.org/Software/Downloads/
COMMENT=	Convert between UTF-8 Unicode and 7-bit ASCII equivalents
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ascii2uni ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uni2ascii ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ascii2uni.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/uni2ascii.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
