# $NetBSD: Makefile,v 1.4 2014/01/15 02:33:47 outpaddling Exp $
#

DISTNAME=	twintk-0.9.4.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	88e139b53bdb4f576e90b8ebebbc2262bfcda606

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/twintk
COMMENT=	Terminal Windows Toolkit
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-patch:
	${MV} ${WRKSRC}/terminfo/M ${WRKSRC}/terminfo/m
	${MV} ${WRKSRC}/terminfo/N ${WRKSRC}/terminfo/n
	${MV} ${WRKSRC}/terminfo/P ${WRKSRC}/terminfo/p
	${MV} ${WRKSRC}/terminfo/Q ${WRKSRC}/terminfo/q
	${MV} ${WRKSRC}/terminfo/T ${WRKSRC}/terminfo/t
	${MV} ${WRKSRC}/terminfo/X ${WRKSRC}/terminfo/x
.endif

.include "../../wip/libbacon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
