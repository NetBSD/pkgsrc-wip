# $NetBSD: Makefile,v 1.1.1.1 2009/02/14 14:03:25 obache Exp $
#

.include "../../wip/sj3/Makefile.common"

PKGNAME=	${DISTNAME:S/sj3-/sj3-client-/}

COMMENT=	SJ3 Japanese input method client & library

CONFLICTS=	sj3-lib-[0-9]* sj3-server-bin-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-client

.include "../../mk/bsd.pkg.mk"
