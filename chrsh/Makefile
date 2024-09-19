# $NetBSD: Makefile,v 1.9 2012/09/24 17:42:07 asau Exp $
#

DISTNAME=	chrsh
PKGNAME=	chrsh-1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.aarongifford.com/computers/
EXTRACT_SUFX=	.c

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.aarongifford.com/computers/chrsh.html
COMMENT=	Chroot jail wrapper for ordinary Unix shells

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} $${extract_file} .

RCS_HEAD=	$$NetBSD: Makefile,v 1.9 2012/09/24 17:42:07 asau Exp $$

do-build:
	cd ${WRKSRC} && \
	${CC} -o chrsh chrsh.c

pre-install:
	${SED} -e 's:@PREFIX@:@RCS@:' \
		${WRKSRC}/chrsh.1 > ${WRKSRC}/chrsh.1.in
	${SED} -e 's:@RCS@:${RCS_HEAD}:' \
		${WRKSRC}/chrsh.1.in > ${WRKSRC}/chrsh.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chrsh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/chrsh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install:
	${SED} -e 's:@RCS@:@PREFIX@:' \
		${WRKSRC}/chrsh.1.in > ${WRKSRC}/chrsh.1

.include "../../mk/bsd.pkg.mk"
