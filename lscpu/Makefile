# $NetBSD$

DISTNAME=	lscpu-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=NanXiao/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/NanXiao/lscpu/
COMMENT=	The lscpu for BSD
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lscpu   ${DESTDIR}${PREFIX}/bin/lscpu
	${INSTALL_MAN_DIR} ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN}     ${WRKSRC}/lscpu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
