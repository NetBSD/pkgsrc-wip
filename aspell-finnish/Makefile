# $NetBSD: Makefile,v 1.2 2010/05/04 15:33:13 othyro Exp $
#

DISTNAME=	aspell6-fi-0.7-0
PKGNAME=	aspell-finnish-0.7.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/fi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jkj@kapsi.fi
HOMEPAGE=	http://aspell.net/
COMMENT=	Finnish language support for aspell

PKG_DESTDIR_SUPPORT=    user-destdir

HAS_CONFIGURE=  YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
