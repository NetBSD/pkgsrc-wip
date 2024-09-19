# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:54 asau Exp $
#
#

DISTNAME=	lsh_0.70.orig
PKGNAME=	mg-lsh-0.70
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/l/lsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20020811140533/http://people.cs.uct.ac.za/~mwelz/lsh.html
COMMENT=	DOS compatible command line interpreter

DEPENDS+=	free-[0-9]*:../../sysutils/free


BUILD_TARGET=	lsh
WRKSRC=		${WRKDIR}/lsh-0.70
CFLAGS+=	-DLSH_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
CONFLICTS+=	lsh-[0-9]*:../../security/lsh

EGDIR=		${PREFIX}/share/examples/mg-lsh
CONF_FILES=	${EGDIR}/autoexec ${PKG_SYSCONFDIR}/autoexec

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
