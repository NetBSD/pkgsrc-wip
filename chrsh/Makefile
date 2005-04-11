# $NetBSD: Makefile,v 1.3 2005/04/11 21:10:29 tvierling Exp $
#

DISTNAME=	chrsh
PKGNAME=	chrsh-1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.aarongifford.com/computers/
EXTRACT_SUFX=	.c

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.aarongifford.com/computers/chrsh.html
COMMENT=	Chroot jail wrapper for ordinary Unix shells

WRKSRC=         ${WRKDIR}
EXTRACT_CMD=	${CP} $${extract_file} .

RCS_HEAD=	$$NetBSD: Makefile,v 1.3 2005/04/11 21:10:29 tvierling Exp $$

do-build:
	cd ${WRKSRC} && \
	cc -o chrsh chrsh.c

pre-install:
	${SED} -e 's:@PREFIX@:@RCS@:' \
		${WRKSRC}/chrsh.1 > ${WRKSRC}/chrsh.1.in
	${SED} -e 's:@RCS@:${RCS_HEAD}:' \
		${WRKSRC}/chrsh.1.in > ${WRKSRC}/chrsh.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chrsh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/chrsh.1 ${PREFIX}/man/man1

post-install:
	${SED} -e 's:@RCS@:@PREFIX@:' \
		${WRKSRC}/chrsh.1.in > ${WRKSRC}/chrsh.1

.include "../../mk/bsd.pkg.mk"
