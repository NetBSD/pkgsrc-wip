# $NetBSD: Makefile,v 1.1.1.1 2008/01/04 04:15:19 netcap Exp $
#

DISTNAME=	plod-1.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.far2wise.net/plod/ \
		http://jfranz.users.bsdprojects.net/distfiles/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.far2wise.net/plod/
COMMENT=	System administration journaling tool

REPLACE_PERL+=	plod

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/plod ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/plod.1.gz ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/plod.el ${EMACS_LISPPREFIX}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
