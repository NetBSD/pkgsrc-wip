# $NetBSD: Makefile,v 1.5 2012/11/14 00:30:06 othyro Exp $
#

DISTNAME=		kawa-1.8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=kawa/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gnu.org/software/kawa/
COMMENT=		Scheme interpreter written in Java

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
