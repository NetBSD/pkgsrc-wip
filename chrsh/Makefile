# $NetBSD: Makefile,v 1.5 2006/05/01 14:20:07 shattered Exp $
#

DISTNAME=	chrsh
PKGNAME=	chrsh-1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.adg.us/computers/
EXTRACT_SUFX=	.c

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.adg.us/computers/chrsh.html
COMMENT=	Chroot jail wrapper for ordinary Unix shells

WRKSRC=         ${WRKDIR}
EXTRACT_CMD=	${CP} $${extract_file} .

RCS_HEAD=	$$NetBSD: Makefile,v 1.5 2006/05/01 14:20:07 shattered Exp $$

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
	${INSTALL_DATA} ${WRKSRC}/chrsh.1 ${PREFIX}/${PKGMANDIR}/man1

post-install:
	${SED} -e 's:@RCS@:@PREFIX@:' \
		${WRKSRC}/chrsh.1.in > ${WRKSRC}/chrsh.1

.include "../../mk/bsd.pkg.mk"
