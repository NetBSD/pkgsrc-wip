# $NetBSD: Makefile,v 1.1 2015/06/16 18:28:35 ishit Exp $

DISTNAME=	pxz-4.999.9b4
CATEGORIES=	archivers
GIT_REPO=	https://github.com/jnovy/pxz.git

MAINTAINER=	ishit@users.sourceforge.net
HOMEPAGE=	https://jnovy.fedorapeople.org/pxz/
COMMENT=	Parallel LZMA compressor using liblzma
LICENSE=	gnu-gpl-v2

DEPENDS+=	xz>=5:../../archivers/xz

_GIT_FLAGS?=	--depth 1
AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxz ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pxz.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
